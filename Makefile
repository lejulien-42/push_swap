# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 13:10:44 by lejulien          #+#    #+#              #
#    Updated: 2021/04/02 13:28:10 by lejulien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_UTILS = ./srcs/utils/ft_atoi.c ./srcs/utils/ft_putnbr_fd.c \
			 ./srcs/utils/ft_putstr.c ./srcs/utils/ft_sqrt.c \
			 ./srcs/utils/ft_itoa.c ./srcs/utils/ft_strcmp.c
SRCS_CHECKER = ./srcs/checker/checker.c ./srcs/checker/actions.c \
			   ./srcs/checker/error.c ./srcs/checker/checker2.c \
			   ./srcs/checker/entry.c ./srcs/checker/check_stack.c \
			   ./srcs/checker/parse_entry.c
SRCS_PUSH_SWAP = ./srcs/push_swap/push_swap.c ./srcs/push_swap/actions.c \
			  	 ./srcs/push_swap/error.c ./srcs/push_swap/action2.c \
			  	 ./srcs/push_swap/check_stack.c ./srcs/push_swap/bubblesort.c \
				 ./srcs/push_swap/sort.c ./srcs/push_swap/push_swap2.c \
				 ./srcs/push_swap/chunked.c ./srcs/push_swap/goto.c \
				 ./srcs/push_swap/count.c ./srcs/push_swap/last_max.c \
				 ./srcs/push_swap/sort_chunk.c
OBJS_UTILS = $(SRCS_UTILS:.c=.o)
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)
OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)

NAME	= checker

GCC		= gcc

FLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

.PHONY:	clean fclean re

$(NAME):	$(OBJS_UTILS) $(OBJS_CHECKER) $(OBJS_PUSH_SWAP)
	gcc -o $(NAME) $(FLAGS) $(OBJS_UTILS) $(OBJS_CHECKER)
	gcc -o push_swap $(FLAGS) $(OBJS_UTILS) $(OBJS_PUSH_SWAP)

clean:
	rm -f $(OBJS_CHECKER) $(OBJS_PUSH_SWAP) $(OBJS_UTILS)

fclean: clean
	rm -f $(NAME)
	rm -f push_swap

re: fclean all

%.o: %.c
	$(GCC) -c $<  -o $(<:.c=.o)
