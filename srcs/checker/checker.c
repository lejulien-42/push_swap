/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:01:57 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/05 23:47:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"
#include <unistd.h>
#include "checker.h"
#include <stdlib.h>

static int
	push_values_to_stack(t_stack **stack, char **av, int ac, int pos)
{
	int	i;
	t_stack	*b_stack;
	t_stack	*ptr;

	b_stack = NULL;
	i = pos;
	while (i < ac)
	{
		if (add_to_stack(stack, ft_atoi(av[i]), pos))
			return (ft_free_stacks(stack, &b_stack, 1));
		i++;
	}
	ptr = *stack;
	if (has_double(stack))
		return (ft_free_stacks(stack, &b_stack, 1));
	if (ptr->disp == 2)
		display_stack(stack, &b_stack);
	if (entry(stack, &b_stack))
		return (ft_free_stacks(stack, &b_stack, 1));
	return (ft_free_stacks(stack, &b_stack, 1) - 1);
}

static int
	is_flag(char *str)
{
	if (str[0] == '-' && str[1] == 'v')
		return (1);
	return (0);
}

int
	is_number(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] < '0' || c[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int
	check_flags(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac > 2)
	{
		if (is_flag(av[1]))
			i++;
	}
	return (1 + i);
}

int
	main(int ac, char **av)
{
	t_stack	*a_stack;
	int		flags;

	a_stack = NULL;
	if (ac > 1)
	{
		if (!(flags = check_flags(ac, av)))
		{
			ft_putstr("Error\n");
			return (1);
		}
		if (push_values_to_stack(&a_stack, av, ac, flags))
		{
			ft_putstr("Error\n");
			return (1);
		}
	}
	else
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}
