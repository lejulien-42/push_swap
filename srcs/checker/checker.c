/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:01:57 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/05 17:08:13 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"
#include <unistd.h>
#include "checker.h"
#include <stdlib.h>

int
	add_to_stack(t_stack *stack, int value)
{
	t_stack	*new;
	t_stack	*ptr;

	ptr = stack;
	if (!(new = malloc(sizeof(stack))))
		return (1);
	if (stack == NULL)
	{
		stack = new;
		return (0);
	}
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
	return (0);
}

static int
	push_values_to_stack(t_stack *stack, char **av, int ac)
{
	int	i;

	i = 1;
	while (1 <= ac)
	{
		if (add_to_stack(stack, ft_atoi(av[i])))
			return (1);
		i++;
	}
	return (0);
}

int
	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	if (ac > 1)
	{
		if (push_values_to_stack(a_stack, av, ac))
		{
			ft_putstr("Error\n");
			return (ft_free_stacks(a_stack, b_stack), 1);
		}
	}
	else
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (ft_free_stacks(a_stack, b_stack), 0);
}
