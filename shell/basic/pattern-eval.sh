#!/bin/bash

function basename
{
	local filename=${1:?"no argument"}
	filename=${filename##*/}

	echo $filename
}

function dirname
{
	local dir=${1:?"no argument"}
	dir=${dir%/*}

	echo $dir
}

echo "basename is: $(basename $1)"
echo "dirname is: $(dirname $1)"
