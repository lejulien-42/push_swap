/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:59:25 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/05 17:06:43 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"

static void
	ft_free_stack(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*ptr2;

	ptr = *stack;
	while (ptr != NULL)
	{
		ptr2 = ptr;
		while (ptr2->next != NULL)
			ptr2 = ptr2->next;
		free(ptr2);
	}
}

int
	ft_free_stacks(t_stack **a_stack, t_stack **b_stack, int ret)
{
	ft_free_stack(s_stack);
	ft_free_stack(b_stack);
	return (ret);
}
