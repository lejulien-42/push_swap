/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:39:16 by lejulien          #+#    #+#             */
/*   Updated: 2021/04/01 13:40:34 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>
#include "../utils/utils.h"

void
	check_stack(t_stack **stack)
{
	t_stack	*ptr;
	int		prev;

	ptr = *stack;
	if (ptr == NULL)
		return (ft_putstr("KO\n"));
	if (ptr->next == NULL)
	{
		ft_putstr("OK\n");
		return ;
	}
	prev = ptr->value;
	ptr = ptr->next;
	while (ptr != NULL)
	{
		if (prev > ptr->value)
		{
			ft_putstr("KO\n");
			return ;
		}
		prev = ptr->value;
		ptr = ptr->next;
	}
	ft_putstr("OK\n");
}
