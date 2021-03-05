/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:01:57 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/05 19:35:42 by user42           ###   ########.fr       */
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

	i = pos;
	while (i < ac)
	{
		if (add_to_stack(stack, ft_atoi(av[i]), pos))
			return (1);
		i++;
	}
	return (0);
}

static int
	is_flag(char *str)
{
	if (str[0] == '-' && str[1] == 'v')
		return (1);
	return (0);
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
	else
		return (0);
	return (1 + i);
}

int
	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int		flags;

	a_stack = NULL;
	b_stack = NULL;
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
			return (ft_free_stacks(&a_stack, &b_stack, 1));
		}
		display_stack(&a_stack, &b_stack);
	}
	else
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (ft_free_stacks(&a_stack, &b_stack, 0));
}
