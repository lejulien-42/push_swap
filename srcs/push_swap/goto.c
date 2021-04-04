/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:34:57 by lejulien          #+#    #+#             */
/*   Updated: 2021/04/04 17:54:41 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../utils/utils.h"

static void
	ft_goto_rotate(t_stack **stack, int pos, char *name)
{
	while (pos != 0)
	{
		rotate(stack);
		ft_putstr("r");
		ft_putstr(name);
		ft_putstr("\n");
		pos--;
	}
}

static void
	ft_goto_r_rotate(t_stack **stack, int pos, char *name)
{
	while (pos != stack_len(stack))
	{
		r_rotate(stack);
		ft_putstr("rr");
		ft_putstr(name);
		ft_putstr("\n");
		pos++;
	}
}

void
	ft_goto(t_stack **stack, int val, char *name)
{
	t_stack	*ptr;
	int		pos;

	pos = 0;
	ptr = *stack;
	while (ptr && ptr->value != val)
	{
		ptr = ptr->next;
		pos++;
	}
	if (pos == 0)
		return ;
	if (pos <= (int)(stack_len(stack) / 2))
		ft_goto_rotate(stack, pos, name);
	else
		ft_goto_r_rotate(stack, pos, name);
}
