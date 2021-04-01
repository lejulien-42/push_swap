/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:50:27 by lejulien          #+#    #+#             */
/*   Updated: 2021/04/01 17:42:34 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include "../utils/utils.h"

int
	check_stack(t_stack **stack)
{
	t_stack	*ptr;
	int		prev;

	ptr = *stack;
	if (ptr == NULL)
		return (1);
	if (ptr->next == NULL)
		return (1);
	prev = ptr->value;
	ptr = ptr->next;
	while (ptr != NULL)
	{
		if (prev > ptr->value)
			return (1);
		prev = ptr->value;
		ptr = ptr->next;
	}
	return (0);
}

int
	r_check_stack(t_stack **stack)
{
	t_stack	*ptr;
	int		prev;

	ptr = *stack;
	if (ptr == NULL)
		return (1);
	if (ptr->next == NULL)
		return (1);
	prev = ptr->value;
	ptr = ptr->next;
	while (ptr != NULL)
	{
		if (prev < ptr->value)
			return (1);
		prev = ptr->value;
		ptr = ptr->next;
	}
	return (0);
}

int
	biggest(t_stack **stack)
{
	t_stack *ptr;
	int		val;

	ptr = *stack;
	val = ptr->value;
	ptr = ptr->next;
	while (ptr)
	{
		if (ptr->value > val)
			val = ptr->value;
		ptr = ptr->next;
	}
	return (val);
}

int
	val_pos(int val, t_stack **stack)
{
	int		i;
	t_stack	*ptr;

	i = 0;
	ptr = *stack;
	while (ptr)
	{
		if (val == ptr->value)
			return (i);
		i++;
		ptr = ptr->next;
	}
	return (-1);
}

void
	move_top(int val, t_stack **stack)
{
	int		length;
	int		pos;

	length = part_length(stack, 0);
	if (pos < (length / 2))
	{
		print_val("val = ", val);
		while (pos <= (length / 2))
		{
			rotate(stack);
			ft_putstr("ra\n");
			pos++;
		}
	}
	else
	{
		while (pos < length)
		{
			r_rotate(stack);
			ft_putstr("rra\n");
			pos++;
		}
	}
}
