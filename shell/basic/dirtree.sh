#!/bin/bash

SPACE="|    "
SLASH='|----'

showtree()
{
	local prefix=$1
	local pathname=$2

	if ! [ -e $pathname ];
	then
		return		
	fi

	echo -e "${prefix}${SLASH}${pathname}"

	if [ -d $pathname ];
	then
		local files=`ls $pathname`		
		for file in $files;
		do			
			showtree "${prefix}${SPACE}" ${pathname%/}/$file
		done
	fi
}

for filename in $@;
do
	showtree '' $filename
done
