/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:57:06 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/11 13:29:48 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int
	add_to_stack(t_stack **stack, int value, int is_disp)
{
	t_stack	*new;
	t_stack	*ptr;

	ptr = *stack;
	if (!(new = malloc(sizeof(stack))))
		return (1);
	new->value = value;
	new->next = NULL;
	new->disp = is_disp;
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

void
	push(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*ptr;

	if (*a_stack == NULL)
		return ;
	ptr = *a_stack;
	*a_stack = ptr->next;
	ptr->next = *b_stack;
	*b_stack = ptr;
}

void
	swap(t_stack **stack)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack;
	if (!a)
		return ;
	b = a->next;
	if (!b)
		return ;
	*stack = b;
	a->next = b->next;
	b->next = a;
}

void
	rotate(t_stack **stack)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack;
	if (!a)
		return ;
	b = a->next;
	if (!b)
		return ;
	while (b->next != NULL)
		b = b->next;
	*stack = a->next;
	b->next = a;
	a->next = NULL;
}

void
	r_rotate(t_stack **stack)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack;
	if (!a)
		return ;
	b = a->next;
	if (!b)
		return ;
	while (b->next != NULL)
	{
		a = a->next;
		b = b->next;
	}
	a->next = NULL;
	b->next = *stack;
	*stack = b;
}
