/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:57:06 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/05 15:59:02 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"

int
	add_to_stack(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*ptr;

	ptr = *stack;
	if (!(new = malloc(sizeof(stack))))
		return (1);
	new->value = value;
	new->next = NULL;
	if (*stack == NULL)
	{
		*stack = new;
		return (0);
	}
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
	return (0);
}
