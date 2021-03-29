#!/bin/bash

export ARG="200 2 0 -4 5 1232 3333 1111111"

make re
./push_swap $ARG | ./checker $ARG
make fclean
