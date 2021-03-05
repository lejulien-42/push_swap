/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:59:25 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/05 18:07:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"
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
	ft_free_stack(b_stack);
	return (ret);
}
