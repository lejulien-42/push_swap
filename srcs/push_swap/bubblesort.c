/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:30:32 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/11 16:36:25 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../utils/utils.h"
#include <stdlib.h>

void
	bubble_sort(t_stack **stack, int ac)
{
	t_stack	*ptr1;
	t_stack	*ptr2;
	t_stack *nill;
	int		i;

	nill = NULL;
	i = 0;
	while (check_stack(stack))
	{
		ptr1 = *stack;
		ptr2 = ptr1->next;
		if (ptr1->value > ptr2->value)
		{
			swap(stack);
			ft_putstr("sa\n");
		}
		if (check_stack(stack))
		{
			rotate(stack);
			ft_putstr("ra\n");
		}
		i++;
		if (i == (ac - 1))
		{
			rotate(stack);
			ft_putstr("ra\n");
			i = 0;
		}
	}
}
