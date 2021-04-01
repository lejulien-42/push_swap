/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:53:40 by lejulien          #+#    #+#             */
/*   Updated: 2021/04/01 14:27:24 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../utils/utils.h"
#include <unistd.h>
#include <stdlib.h>

char
	*add_char(char *src, char c)
{
	char	*ret;
	int		index;

	index = 0;
	if (src == NULL)
	{
		if (!(ret = malloc(2 * sizeof(char))))
			return (NULL);
		ret[0] = c;
		ret[1] = '\0';
		return (ret);
	}
	if (!(ret = malloc((ft_strlen(src) + 1) * sizeof(char))))
		return (NULL);
	while (src[index] != '\0')
	{
		ret[index] = src[index];
		index++;
	}
	ret[index] = c;
	ret[index + 1] = '\0';
	free(src);
	return (ret);
}

int
	entry(t_stack **a_stack, t_stack **b_stack)
{
	int		run;
	char	c;
	char	*entry;
	int		ret;

	run = 1;
	entry = NULL;
	while (run)
	{
		ret = read(0, &c, 1);
		if (ret == -1 || ret == 0 || c == '\x4')
			run = 0;
		entry = add_char(entry, c);
		if (c == '\n')
		{
			ret = parse_entry(entry, a_stack, b_stack);
			free(entry);
			if (ret == 1)
				return (1);
			entry = NULL;
		}
	}
	free(entry);
	(*b_stack != NULL) ? ft_putstr("KO\n") : check_stack(a_stack);
	return (0);
}
