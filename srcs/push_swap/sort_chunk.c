/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:02:43 by lejulien          #+#    #+#             */
/*   Updated: 2021/04/01 18:03:58 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../utils/utils.h"

static void
	put_prev_chunk_down(t_stack **a_stack, t_stack **test_stack, int part)
{
	t_stack	*ptr;
	int		last;

	ptr = *a_stack;
	if (part == 1)
		return ;
	while (ptr && ptr->part != part - 1)
		ptr = ptr->next;
	while (ptr && ptr->part == part - 1)
		ptr = ptr->next;
	if (ptr)
		ft_goto(a_stack, ptr->value, "a");
	else
	{
		ptr = *a_stack;
		ft_goto(a_stack, ptr->value, "a");
	}
}

void
	pa(t_stack **a_stack, t_stack **b_stack)
{
	push(b_stack, a_stack);
	ft_putstr("pa\n");
}

void
	ra(t_stack **a_stack)
{
	rotate(a_stack);
	ft_putstr("ra\n");
}

static void
	put_in_last(t_stack **a_stack, t_stack **b_stack, t_stack **test_stack,
				int part)
{
	int		i;
	int		len;
	t_stack	*ptr;
	t_stack	*a_ptr;

	ptr = *b_stack;
	if (!ptr)
		return ;
	len = part_length(b_stack, part);
	i = 0;
	if (len != part_length(test_stack, part))
		return ;
	a_ptr = *a_stack;
	put_prev_chunk_down(a_stack, test_stack, part);
	while (i < len)
	{
		pa(a_stack, b_stack);
		i++;
	}
	i = 0;
	while (i < len)
	{
		ra(a_stack);
		i++;
	}
}

void
	sort_chunck(t_stack **a_stack, t_stack **b_stack, t_stack **test_stack,
				int nbr)
{
	t_stack	*a_ptr;
	int		i;
	int		j;

	i = 0;
	while (i < nbr)
	{
		j = 0;
		while (j < part_length(test_stack, i + 1))
		{
			a_ptr = *a_stack;
			while (is_val_in_part(test_stack, a_ptr->value, i + 1) == 0)
			{
				ra(a_stack);
				a_ptr = *a_stack;
			}
			a_ptr->part = i + 1;
			place_val(a_ptr->value, b_stack, a_stack, i + 1);
			j++;
		}
		ft_goto(b_stack, biggest(b_stack), "b");
		put_in_last(a_stack, b_stack, test_stack, i + 1);
		i++;
	}
}
