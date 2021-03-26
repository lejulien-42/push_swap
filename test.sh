#!/bin/bash

export ARG="2 1 6 4 3"

make re
./push_swap $ARG | ./checker -v $ARG
echo "__"
echo "||"
echo "||"
echo "\/ operations"
./push_swap $ARG | grep -c ""
make fclean
