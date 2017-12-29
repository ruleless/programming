#!/bin/bash
# sed command format:
#   [address] instruction
#
# address format are as bellow:
#   1. digit: 1 for line 1
#   2. regular expression in slash(/): like /^[ \t]\+/
#   3. address range in above format
#
# instruction supported are as bellow:
#   1. a, i: for append and insert
#   2. d, D: for delete
#   3. s: for substitution
#   4. p: print
