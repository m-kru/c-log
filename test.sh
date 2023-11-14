#/bin/bash

set -e

echo -e "Default Configuration Test"
gcc main.c
./a.out

echo -e "\nColors Test"
gcc -DLOG_COLOR main.c
./a.out

echo -e "\nSource Test"
gcc -DLOG_SOURCE main.c
./a.out

echo -e "\nTime Test"
gcc -DLOG_TIME main.c
./a.out

echo -e "\nDate, Color and Source Test"
gcc -DLOG_TIME -DLOG_COLOR -DLOG_SOURCE main.c
./a.out
