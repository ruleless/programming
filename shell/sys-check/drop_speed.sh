#!/bin/sh

get_eth_dev()
{
	CMD="cat /proc/net/dev|sed 's/[|:]/ /g'| grep "$1" | awk '{
if(\$$2~/[0123456789]/) count += \$$2}
END{print count}'"
	RET=`eval $CMD`
	echo $RET
}

get_net_dev()
{
	CMD="cat /proc/net/dev|sed 's/[|:]/ /g'|awk '{
if(\$$1~/[0123456789]/) count += \$$1}
END{print count}'"
	RET=`eval $CMD`
	echo $RET
}

format_bytes()
{
	local b=$1
	if [ $b -lt 1024 ]; then
		echo "$b B"
	elif [ $b -lt $((1024*1024)) ]; then
		echo "$((b/1024)) KB"
	elif [ $b -lt $((1024*1024*1024)) ]; then
		echo "$((b/1024/1024)) MB"
	else
		echo "$((b/1024/1024/1024)) GB"
	fi
}

INTERVAL=${1:-5}

ex_time=`date +%s`
ex_drop_count=$(get_net_dev 5)
ex_rx_bytes=$(get_net_dev 2)
ex_eth0_bytes=$(get_eth_dev eth0 2)
ex_eth1_bytes=$(get_eth_dev eth1 2)
ex_eth2_bytes=$(get_eth_dev eth2 2)

while true; do
	sleep $INTERVAL
	
	cur_time=`date +%s`
	cur_drop_count=$(get_net_dev 5)
	cur_rx_bytes=$(get_net_dev 2)
	cur_eth0_bytes=$(get_eth_dev eth0 2)
	cur_eth1_bytes=$(get_eth_dev eth1 2)
	cur_eth2_bytes=$(get_eth_dev eth2 2)
	
	if [ ! $cur_time -eq $ex_time ]; then
		time_int=$(($cur_time - $ex_time))
		drop_count=$(($cur_drop_count-$ex_drop_count))
		rx_bytes=$(($cur_rx_bytes-$ex_rx_bytes))
		eth0_bytes=$(($cur_eth0_bytes-$ex_eth0_bytes))
		eth1_bytes=$(($cur_eth1_bytes-$ex_eth1_bytes))
		eth2_bytes=$(($cur_eth2_bytes-$ex_eth2_bytes))
		
		drop_speed=`echo -n $drop_count $time_int | awk '{ printf "%.2f",$1/$2 }'`
		rx_speed=`echo -n $rx_bytes $time_int | awk '{ printf "%.0f",$1/$2 }'`
		rx_speed=$(format_bytes $rx_speed)
		eth0_speed=`echo -n $eth0_bytes $time_int | awk '{ printf "%.0f",$1/$2 }'`
		eth0_speed=$(format_bytes $eth0_speed)
		eth1_speed=`echo -n $eth1_bytes $time_int | awk '{ printf "%.0f",$1/$2 }'`
		eth1_speed=$(format_bytes $eth1_speed)
		eth2_speed=`echo -n $eth2_bytes $time_int | awk '{ printf "%.0f",$1/$2 }'`
		eth2_speed=$(format_bytes $eth2_speed)

		ex_time=$cur_time
		ex_drop_count=$cur_drop_count
		ex_rx_bytes=$cur_rx_bytes
		ex_eth0_bytes=$cur_eth0_bytes
		ex_eth1_bytes=$cur_eth1_bytes
		ex_eth2_bytes=$cur_eth2_bytes
		
		echo "rx drop packet: $cur_drop_count  drop speed: $drop_speed /s  rx recv speed: $rx_speed/s"
		echo "  eth0 recv speed: $eth0_speed/s"
		echo "  eth1 recv speed: $eth1_speed/s"
		echo "  eth2 recv speed: $eth2_speed/s"
	fi
done
