/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:32:28 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/29 17:46:33 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../utils/utils.h"
#include <stdlib.h>

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
	else if (ptr->value > ptr->next->value && ptr->next->value > ptr->next->next->value)
	{
		swap(a_stack);
		ft_putstr("sa\n");
		r_rotate(a_stack);
		ft_putstr("rra\n");
	}
	else if (ptr->next->value < ptr->next->next->value && ptr->next->next->value < ptr->value)
	{
		rotate(a_stack);
		ft_putstr("ra\n");
	}
	else if (ptr->value < ptr->next->next->value && ptr->next->next->value < ptr->next->value)
	{
		swap(a_stack);
		ft_putstr("sa\n");
		rotate(a_stack);
		ft_putstr("ra\n");
	}
	else if (ptr->next->next->value < ptr->value && ptr->value < ptr->next->value)
	{
		r_rotate(a_stack);
		ft_putstr("rra\n");
	}
}

void
	sort(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*test_stack;
	int		parts;

	parts = (int)(ft_sqrt(500) / 2.0);
	if (part_length(a_stack, 0) == 3)
		sort_3(a_stack);
	else
	{
		stack_dup(&test_stack, a_stack);
		bubble_sort(&test_stack, part_length(&test_stack, 0));
		chunked(&test_stack, parts);
		sort_chunck(a_stack, b_stack, &test_stack, parts);
		ft_free_stack(&test_stack);
	}
}
