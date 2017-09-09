#!/bin/bash


IFS=','
echo '$*':$*
echo '$@':$@
echo '$#':$#

arg1=$1
# echo '${arg1:-default}='${arg1:-default}
echo '${arg1:=default}='${arg1:=default}
echo '${arg1:?"undefined"}='${arg1:?"undefined"}
# echo '${arg1:+default}='${arg1:+default}
echo ${arg1:1}
