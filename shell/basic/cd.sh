#!/bin/bash

cd()
{
	local curdir=$PWD
	local destdir=$@
	builtin cd "$destdir"
	local r=$?
	echo "$curdir -> $destdir"
	echo `ls`
	return $r
}

cd $@
