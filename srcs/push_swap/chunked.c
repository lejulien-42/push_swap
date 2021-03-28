/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunked.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:26:29 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/28 14:54:55 by lejulien         ###   ########.fr       */
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

	i = 0;
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
			if (ptr->next->part != start_part + 1)
				rotate(stack);
			i++;
		}
		nbr--;
	}
	rotate(stack);
}

// This one will need to be optimized

static void
	place_val(int val, t_stack **b_stack, t_stack **a_stack, int part)
{
	t_stack	*ptr;
	int		start;

	ptr = *b_stack;
	if (*b_stack == NULL || (ptr && val > ptr->value))
	{
		push(a_stack, b_stack);
		ft_putstr("pb\n");
	}
	else if (val < get_last_val(b_stack))
	{
		push(a_stack, b_stack);
		ft_putstr("pb\n");
		rotate(b_stack);
		ft_putstr("rb\n");
	}
	else
	{
		start = ptr->value;
		while (val < ptr->value)
		{
			rotate(b_stack);
			ft_putstr("rb\n");
			ptr = *b_stack;
		}
		push(a_stack, b_stack);
		ft_putstr("pb\n");
		while (ptr->value != start)
		{
			r_rotate(b_stack);
			ft_putstr("rrb\n");
			ptr = *b_stack;
		}
	}
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

static void
	put_prev_chunk_down(t_stack **a_stack, t_stack **test_stack, int part)
{
	t_stack	*ptr;
	int		last;

	ptr = *test_stack;
	if (part == 1)
		return ;
	while (ptr && ptr->part != part - 1)
		ptr = ptr->next;
	while (ptr && ptr->next && ptr->next->part == part - 1)
		ptr = ptr->next;
	last = ptr->value;
	while (1)
	{
		ptr = *a_stack;
		while (ptr && ptr->next)
			ptr = ptr->next;
		if (ptr->value == last)
			return ;
		rotate(a_stack);
		ft_putstr("ra\n");
	}
}

static void
	put_in_last(t_stack **a_stack, t_stack **b_stack, t_stack **test_stack, int part)
{
	int		i;
	int		len;
	t_stack	*ptr;
	t_stack	*a_ptr;

	ptr = *b_stack;
	if (!ptr)
		return ;
	len = part_length(b_stack, part);
	i = 0;
	if (len != part_length(test_stack, part))
		return ;
	a_ptr = *a_stack;
	put_prev_chunk_down(a_stack, test_stack, part);
	while (i < len)
	{
		push(b_stack, a_stack);
		ft_putstr("pa\n");
		i++;
	}
	i = 0;
	while (i < len)
	{
		rotate(a_stack);
		ft_putstr("ra\n");
		i++;
	}
	if (part == 3)
		return;
}

// last time here

void
	sort_chunck(t_stack **a_stack, t_stack **b_stack, t_stack **test_stack, int nbr)
{
	t_stack	*a_ptr;
	int		i;
	int		j;

	i = 0;
	while (i < nbr)
	{
		j = 0;
		while (j < part_length(test_stack, i + 1))
		{
			a_ptr = *a_stack;
			while (is_val_in_part(test_stack, a_ptr->value, i + 1) == 0)
			{
				rotate(a_stack);
				ft_putstr("ra\n");
				a_ptr = *a_stack;
			}
			a_ptr->part = i + 1;
			place_val(a_ptr->value, b_stack, a_stack, i + 1);
			j++;
		}
		put_in_last(a_stack, b_stack, test_stack, i + 1);
		i++;
		if (i == 3)
			return ;
	}
}
