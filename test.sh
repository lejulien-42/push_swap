#!/bin/bash

export ARG="200 2 1 6 4 3 0 9 12 43 22 -4 -23 46 -2 65 74 33 88 99 100"

make re
./push_swap $ARG | ./checker $ARG
export ARG="3 1 2 5 6 4 7 0"
./push_swap $ARG | ./checker $ARG
make fclean
