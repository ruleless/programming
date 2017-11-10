#!/bin/sh

PID=${1:-`pidof nginx`}
PID=`echo $PID | awk '{ print $1 }'`

tcpnum=`ss -anp | grep $PID | wc -l`
fdnum=`ls -ls /proc/$PID/fd | grep socket | wc -l`

echo "PID=${PID}: tcpnum=${tcpnum}, fdnum=${fdnum}"
