#!/bin/bash

export ARG="1 3 2 5 9 7 14 6 42 -1 -2 -3"

make re
./push_swap $ARG | ./checker -v $ARG
echo "__"
echo "||"
echo "||"
echo "\/ operations"
./push_swap $ARG | grep -c ""
make fclean