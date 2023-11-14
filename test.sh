#/bin/bash

set -e

echo -e "Default configuration test\n"
gcc main.c
./a.out

echo -e "\n\nColors test\n"
gcc -DLOG_COLOR main.c
./a.out

echo -e "\n\nSource test\n"
gcc -DLOG_SOURCE main.c
./a.out
