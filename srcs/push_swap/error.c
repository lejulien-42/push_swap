/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:59:25 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/17 09:07:22 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "../utils/utils.h"
#include <unistd.h>

static void
	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*nxt;

	if (!*stack)
		return ;
	tmp = *stack;
	while (tmp != NULL)
	{
		nxt = tmp->next;
		free(tmp);
		tmp = nxt;
	}
	*stack = NULL;
}


int
	ft_free_stacks(t_stack **a_stack, t_stack **b_stack, int ret)
{
	ft_free_stack(a_stack);
	if (b_stack != NULL)
		ft_free_stack(b_stack);
	return (ret);
}

int
	has_double(t_stack **stack)
{
	t_stack	*ptr1;
	t_stack	*ptr2;

	ptr1 = *stack;
	ptr2 = ptr1->next;
	while (ptr1->next != NULL)
	{
		ptr2 = ptr1->next;
		while (ptr2 != NULL)
		{
			if (ptr1->value == ptr2->value)
				return (1);
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return (0);
}

void
	ft_puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}

void
	debug_stack(t_stack **stack)
{
	t_stack	*ptr;

	ptr = *stack;
	while (ptr)
	{
		ft_puterror("[");
		ft_putnbr_fd(ptr->value, 2);
		ft_puterror("][");
		ft_putnbr_fd(ptr->part, 2);
		ft_puterror("]\n");
		ptr = ptr->next;
	}
}

int
	is_part_in_stack(t_stack **stack, int part)
{
	t_stack *ptr;

	ptr = *stack;
	while (ptr)
	{
		if (ptr->part == part)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}