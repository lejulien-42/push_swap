/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:32:28 by lejulien          #+#    #+#             */
/*   Updated: 2021/04/01 15:00:57 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../utils/utils.h"
#include <stdlib.h>

static void
	sort_3_two(t_stack **a_stack, t_stack *ptr)
{
	if (ptr->next->value < ptr->next->next->value &&
			ptr->next->next->value < ptr->value)
	{
		rotate(a_stack);
		ft_putstr("ra\n");
	}
	else if (ptr->value < ptr->next->next->value &&
			ptr->next->next->value < ptr->next->value)
	{
		swap(a_stack);
		ft_putstr("sa\n");
		rotate(a_stack);
		ft_putstr("ra\n");
	}
	else if (ptr->next->next->value < ptr->value &&
			ptr->value < ptr->next->value)
	{
		r_rotate(a_stack);
		ft_putstr("rra\n");
	}
}

static void
	sort_3(t_stack **a_stack)
{
	t_stack *ptr;

	ptr = *a_stack;
	if (ptr->next->value < ptr->value && ptr->value < ptr->next->next->value)
	{
		swap(a_stack);
		ft_putstr("sa\n");
	}
	else if (ptr->value > ptr->next->value &&
			ptr->next->value > ptr->next->next->value)
	{
		swap(a_stack);
		ft_putstr("sa\n");
		r_rotate(a_stack);
		ft_putstr("rra\n");
	}
	else
		sort_3_two(a_stack, ptr);
}

static int
	greater_than(int val, t_stack **stack)
{
	t_stack	*ptr;

	ptr = *stack;
	while (ptr->value != smallest(stack))
		ptr = ptr->next;
	while (ptr->value < val)
	{
		ptr = ptr->next;
		if (!ptr)
			ptr = *stack;
	}
	return (ptr->value);
}

static void
	sort_5(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*ptr;

	while (stack_len(a_stack) != 3)
	{
		push(a_stack, b_stack);
		ft_putstr("pb\n");
	}
	sort_3(a_stack);
	while (*b_stack)
	{
		ptr = *b_stack;
		if (ptr->value < smallest(a_stack) || ptr->value > biggest(a_stack))
			ft_goto(a_stack, smallest(a_stack), "a");
		else
			ft_goto(a_stack, greater_than(ptr->value, a_stack), "a");
		push(b_stack, a_stack);
		ft_putstr("pa\n");
	}
	ft_goto(a_stack, smallest(a_stack), "a");
}

void
	sort(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*test_stack;
	int		parts;

	if (check_stack(a_stack) == 0 || stack_len(a_stack) == 1)
		return ;
	parts = (int)((ft_sqrt(part_length(a_stack, 0))) / 2.0);
	if (part_length(a_stack, 0) == 3)
		sort_3(a_stack);
	else if (part_length(a_stack, 0) == 5)
		sort_5(a_stack, b_stack);
	else if (part_length(a_stack, 0) == 2)
	{
		swap(a_stack);
		ft_putstr("sa\n");
	}
	else
	{
		stack_dup(&test_stack, a_stack);
		bubble_sort(&test_stack, part_length(&test_stack, 0));
		chunked(&test_stack, parts);
		sort_chunck(a_stack, b_stack, &test_stack, parts);
		ft_free_stack(&test_stack);
	}
}
