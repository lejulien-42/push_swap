/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:41:48 by lejulien          #+#    #+#             */
/*   Updated: 2021/04/01 17:42:37 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../utils/utils.h"
#include <stdio.h>

int
	is_val_in_part(t_stack **stack, int val, int part)
{
	t_stack	*ptr;

	ptr = *stack;
	while (ptr && ptr->part != part)
		ptr = ptr->next;
	while (ptr && ptr->part == part)
	{
		if (ptr->value == val)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

static int
	get_max(t_stack **b_stack)
{
	t_stack	*ptr;
	int		max;

	if (!*b_stack)
		return (-1);
	ptr = *b_stack;
	max = ptr->value;
	ptr = ptr->next;
	while (ptr)
	{
		if (ptr->value > max)
			max = ptr->value;
		ptr = ptr->next;
	}
	return (max);
}

void
	go_max(t_stack **b_stack, int part)
{
	t_stack	*ptr;

	ptr = *b_stack;
	if (!*b_stack)
		return ;
	ft_putnbr_fd(get_max(b_stack), 2);
	return ;
	while (ptr->value != get_max(b_stack))
	{
		rotate(b_stack);
		ft_putstr("rb\n");
		ptr = *b_stack;
	}
}

int
	get_last_val(t_stack **stack)
{
	t_stack	*ptr;

	ptr = *stack;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr->value);
}

int
	stack_len(t_stack **stack)
{
	t_stack	*ptr;
	int		i;

	i = 0;
	ptr = *stack;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
