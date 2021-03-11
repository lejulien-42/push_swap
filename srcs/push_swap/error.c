/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:59:25 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/11 13:30:43 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "../utils/utils.h"

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
