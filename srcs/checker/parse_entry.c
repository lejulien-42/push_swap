/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:15:28 by lejulien          #+#    #+#             */
/*   Updated: 2021/04/01 14:16:49 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../utils/utils.h"

int
	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int
	ft_strcmp(char *src, char *dst)
{
	int	i;

	i = 0;
	if (ft_strlen(src) != ft_strlen(dst))
		return (0);
	while (src[i] != '\0')
	{
		if (src[i] != dst[i])
			return (0);
		i++;
	}
	return (1);
}

static int
	parse_entry2(char *str, t_stack **a_stack, t_stack **b_stack)
{
	if (ft_strcmp("ss\n", str))
	{
		swap(a_stack);
		swap(b_stack);
		return (1);
	}
	else if (ft_strcmp("ra\n", str))
	{
		rotate(a_stack);
		return (1);
	}
	else if (ft_strcmp("rb\n", str))
	{
		rotate(b_stack);
		return (1);
	}
	else if (ft_strcmp("rr\n", str))
	{
		rotate(a_stack);
		rotate(b_stack);
	}
	return (0);
}

int
	parse_entry(char *str, t_stack **a_stack, t_stack **b_stack)
{
	if (ft_strcmp("pa\n", str))
		push(b_stack, a_stack);
	else if (ft_strcmp("pb\n", str))
		push(a_stack, b_stack);
	else if (ft_strcmp("sa\n", str))
		swap(a_stack);
	else if (ft_strcmp("sb\n", str))
		swap(b_stack);
	else if (ft_strcmp("rra\n", str))
		r_rotate(a_stack);
	else if (parse_entry2(str, a_stack, b_stack))
	{
	}
	else if (ft_strcmp("rrb\n", str))
		r_rotate(b_stack);
	else if (ft_strcmp("rrr\n", str))
	{
		r_rotate(a_stack);
		r_rotate(b_stack);
	}
	else if (ft_strcmp("\n", str))
		return (0);
	else
		return (1);
	return (0);
}
