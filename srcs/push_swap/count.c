/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:39:08 by lejulien          #+#    #+#             */
/*   Updated: 2021/04/01 17:40:37 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../utils/utils.h"

int
	part_length(t_stack **stack, int part)
{
	int		i;
	t_stack	*ptr;

	i = 0;
	ptr = *stack;
	while (ptr && ptr->part != part)
		ptr = ptr->next;
	while (ptr && ptr->part == part)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

int
	count_parts(t_stack **stack)
{
	int		i;
	int		tmp;
	t_stack	*ptr;

	i = 0;
	tmp = -1;
	ptr = *stack;
	while (ptr)
	{
		if (ptr->part != tmp)
		{
			i++;
			tmp = ptr->part;
		}
		ptr = ptr->next;
	}
	return (1);
}

void
	print_val(char *str, int val)
{
	ft_puterror(str);
	ft_putnbr_fd(val, 2);
	ft_puterror("\n");
}

int
	new_part(t_stack **a_stack, t_stack **b_stack)
{
	int		tmp;
	t_stack	*ptr;

	tmp = -1;
	ptr = *a_stack;
	while (ptr)
	{
		if (tmp < ptr->part)
			tmp = ptr->part;
		ptr = ptr->next;
	}
	ptr = *b_stack;
	while (ptr)
	{
		if (tmp < ptr->part)
			tmp = ptr->part;
		ptr = ptr->next;
	}
	return (tmp + 1);
}

int
	smallest(t_stack **stack)
{
	t_stack *ptr;
	int		val;

	ptr = *stack;
	val = ptr->value;
	ptr = ptr->next;
	while (ptr)
	{
		if (ptr->value < val)
			val = ptr->value;
		ptr = ptr->next;
	}
	return (val);
}
