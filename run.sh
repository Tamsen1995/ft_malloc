#!/bin/sh
make re
cd testr
sh run.sh
gcc -g test1.c
$@
