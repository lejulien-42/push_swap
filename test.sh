#!/bin/bash

export ARG="3 1 2"

make re
./push_swap $ARG | ./checker -v $ARG
echo "__"
echo "||"
echo "||"
echo "\/ operations"
./push_swap $ARG | grep -c ""
make fclean