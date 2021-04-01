/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:52:29 by lejulien          #+#    #+#             */
/*   Updated: 2021/04/01 14:53:06 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void
	stack_dup(t_stack **res, t_stack **src)
{
	t_stack	*ptr;

	*res = NULL;
	ptr = *src;
	while (ptr)
	{
		add_to_stack(res, ptr->value, 0);
		ptr = ptr->next;
	}
}
