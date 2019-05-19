#! /bin/bash

g++ -ggdb -std=c++14 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant *.cpp -o proj2 && ./proj2
