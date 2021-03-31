#!/bin/bash
make re

printf "### CHECKER TEST ###\n"			# checker

printf "1 non-numeric case\n"
export ARG="a"
./checker $ARG
printf "\n\n"

printf "3 non-numeric case\n"
export ARG="a b c"
./checker $ARG
printf "\n\n"

printf "dup case\n"
export ARG="1 1"
./checker $ARG
printf "\n\n"

printf "I_max case\n"
export ARG="1 2147483649"
./checker $ARG
printf "\n\n"

printf "no arg case\n"
./checker
printf "\n\n"

printf "non existing instructions case\n"
export ARG="14 7 9"
printf "patate\n" | ./checker $ARG
printf "\n\n"

printf "space before instructions case\n"
export ARG="14 7 9"
printf " pb\n" | ./checker $ARG
printf "\n\n"

printf "space after instructions case\n"
export ARG="14 7 9"
printf "pb \n" | ./checker $ARG
printf "\n\n"

printf "### PUSH_SWAP TEST ###\n"		# push_swap

printf "one case\n"
export ARG="200"
./push_swap $ARG | ./checker $ARG
printf "len-->"
./push_swap $ARG | grep -c ""
printf "\n\n"

printf "two case\n"
export ARG="500 200"
./push_swap $ARG | ./checker $ARG
printf "len-->"
./push_swap $ARG | grep -c ""
printf "\n\n"

printf "three case\n"
export ARG="200 0 500"
./push_swap $ARG | ./checker $ARG
printf "len-->"
./push_swap $ARG | grep -c ""
printf "\n\n"

printf "five case\n"
export ARG="200 0 88 -42 100"
./push_swap $ARG | ./checker $ARG
printf "len-->"
./push_swap $ARG | grep -c ""
printf "\n\n"

printf "one hundred case\n"
export ARG=`ruby -e "puts (1...100).to_a.shuffle.join(' ')"`
./push_swap $ARG | ./checker $ARG
printf "len-->"
./push_swap $ARG | grep -c ""
printf "\n\n"

printf "five hundred case\n"
export ARG=`ruby -e "puts (1...500).to_a.shuffle.join(' ')"`
./push_swap $ARG | ./checker $ARG
printf "len-->"
./push_swap $ARG | grep -c ""
printf "\n\n"

printf "all-ready solve case\n"
export ARG="0 1 2 3 4 5 6 7 8"
./push_swap $ARG | ./checker $ARG
printf "len-->"
./push_swap $ARG | grep -c ""
printf "\n\n"
