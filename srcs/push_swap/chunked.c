/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunked.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:26:29 by lejulien          #+#    #+#             */
/*   Updated: 2021/04/01 18:03:55 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../utils/utils.h"
#include <stdlib.h>

void
	chunked(t_stack **stack, int nbr)
{
	int		size;
	int		i;
	int		part;
	t_stack	*ptr;
	int		start_part;

	size = part_length(stack, 0);
	size = size / nbr + 1;
	ptr = *stack;
	start_part = ptr->part;
	while (nbr > 0)
	{
		i = 0;
		ptr = NULL;
		part = new_part(stack, &ptr);
		while (i < size)
		{
			ptr = *stack;
			ptr->part = part;
			(ptr->next->part != start_part + 1) ? rotate(stack) : NULL;
			i++;
		}
		nbr--;
	}
	rotate(stack);
}

static int
	find_next_val(t_stack **stack, int val)
{
	t_stack	*ptr;

	ptr = *stack;
	while (ptr->value != biggest(stack))
		ptr = ptr->next;
	while (val < ptr->value)
	{
		ptr = ptr->next;
		if (!ptr)
			ptr = *stack;
	}
	return (ptr->value);
}

void
	place_val(int val, t_stack **b_stack, t_stack **a_stack, int part)
{
	if (*b_stack && val > smallest(b_stack) && val < biggest(b_stack))
		ft_goto(b_stack, find_next_val(b_stack, val), "b");
	else if (*b_stack)
		ft_goto(b_stack, biggest(b_stack), "b");
	push(a_stack, b_stack);
	ft_putstr("pb\n");
}

static int
	is_last_in_part(t_stack **a_stack, int part)
{
	t_stack	*ptr;

	ptr = *a_stack;
	while (ptr->next)
		ptr = ptr->next;
	if (ptr->part == part)
		return (0);
	return (1);
}
