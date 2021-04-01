/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:45:52 by lejulien          #+#    #+#             */
/*   Updated: 2021/04/01 13:52:35 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../utils/utils.h"
#include <stdlib.h>

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

int
	main(int ac, char **av)
{
	t_stack	*a_stack;
	int		flags;

	a_stack = NULL;
	if (ac > 1)
	{
		if (check_num(ac, av) || check_max(ac, av))
		{
			ft_putstr("Error\n");
			return (1);
		}
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
	return (0);
}
