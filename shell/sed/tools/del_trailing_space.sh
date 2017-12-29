#!/bin/bash

TMPNAME=.temp.for.sed.$$
flist=$@

get_mode_num()
{
	local n=0
	if [ ${1:0:1} != '-' ]; then
		n=$((n + 4))
	fi
	if [ ${1:1:1} != '-' ]; then
		n=$((n + 2))
	fi
	if [ ${1:2:1} != '-' ]; then
		n=$((n + 1))
	fi
	echo -n "$n"
}

get_file_mode()
{
	local mode=`ls -ls $1 | awk '{ print $2 }'`
	echo -n "0$(get_mode_num ${mode:1:3})$(get_mode_num ${mode:4:6})$(get_mode_num ${mode:7:9})"
}

for file in $flist
do
	if [ -f $file ];
	then
		if ! grep '[[:space:]]\+$' $file > /dev/null 2>&1
		then
			continue
		fi

		oldmode=$(get_file_mode $file)
		sed 's/[[:space:]]\+$//' $file > $file$TMPNAME
		if [ $? = 0 ];
		then
			mv $file$TMPNAME $file
			chmod $oldmode $file
			echo "delete trailing whitespace for $file"
		else
			rm -f $file$TMPNAME
		fi
	fi
done
