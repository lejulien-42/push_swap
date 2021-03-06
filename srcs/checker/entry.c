#include "checker.h"
#include "../utils/utils.h"
#include <unistd.h>
#include <stdlib.h>

int
	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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
	parse_entry(char *str, t_stack **a_stack, t_stack **b_stack)
{
	if (ft_strcmp("pa\n", str))
		ft_putstr("You've typed pa\n");
	else if (ft_strcmp("pb\n", str))
		ft_putstr("You've typed pb\n");
	else
		return (1);
	return (0);
}

int
	entry(t_stack **a_stack, t_stack **b_stack)
{
	int		run;
	char	c;
	t_stack	*a_ptr;
	t_stack	*b_ptr;
	char	*entry;

	a_ptr = *a_stack;
	b_ptr = *b_stack;
	run = 1;
	entry = NULL;
	while (run)
	{
		if (read(1, &c, 1) == 0)
			run = 0;
		entry = add_char(entry, c);
		if (c == '\n')
		{
			if (parse_entry(entry, a_stack, b_stack))
			{
				free(entry);
				return (1);
			}
			free(entry);
			entry = NULL;
			if (a_ptr != NULL)
			{
				if (a_ptr->disp == 2)
					display_stack(a_stack, b_stack);
			}
		}
	}
	free(entry);
	return (0);
}
