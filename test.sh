#!/bin/bash
make re
./push_swap 1 2 3 -1 -2 -3 | ./checker -v 1 2 3 -1 -2 -3
make fclean