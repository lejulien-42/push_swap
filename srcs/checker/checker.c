/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:01:57 by lejulien          #+#    #+#             */
/*   Updated: 2021/04/01 13:52:16 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"
#include <unistd.h>
#include "checker.h"
#include <stdlib.h>

int
	push_values_to_stack(t_stack **stack, char **av, int ac, int pos)
{
	int		i;
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
	check_num(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				if (av[i][j] != '-')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int
	check_max(int ac, char **av)
{
	int		i;
	char	*tmp;
	int		i_tmp;

	i = 1;
	while (i < ac)
	{
		i_tmp = ft_atoi(av[i]);
		tmp = ft_itoa(i_tmp);
		if (i_tmp != 0 && my_strcmp(av[i], tmp))
		{
			free(tmp);
			return (1);
		}
		free(tmp);
		i++;
	}
	return (0);
}
