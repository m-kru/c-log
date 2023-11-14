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

echo -e "\nColor and Source Test"
gcc -DLOG_COLOR -DLOG_SOURCE main.c
./a.out
