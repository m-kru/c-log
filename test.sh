#/bin/bash

set -e

echo -e "Default Configuration Test\n"
gcc main.c
./a.out

echo -e "\n\nColors Test\n"
gcc -DLOG_COLOR main.c
./a.out

echo -e "\n\nSource Test\n"
gcc -DLOG_SOURCE main.c
./a.out

echo -e "\n\nColor and Source Test\n"
gcc -DLOG_COLOR -DLOG_SOURCE main.c
./a.out
