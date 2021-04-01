/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:03:15 by lejulien          #+#    #+#             */
/*   Updated: 2021/04/01 15:07:13 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"
#include <stdlib.h>

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
