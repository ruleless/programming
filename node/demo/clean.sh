#!/bin/bash

find \( -path ./node_modules -prune -o -name "*.js" \) -exec del_trailing_space {} \;

line_count=`find \( -path ./node_modules -prune -o -name "*.js" \) -exec cat {} \; | awk 'BEGIN{c} {if (length>0) c+=1;} END{print c}'`
echo "total line count of source file: $line_count"
