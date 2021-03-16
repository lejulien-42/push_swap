#include "push_swap.h"
#include <stdlib.h>
#include "../utils/utils.h"

int
	check_stack(t_stack **stack)
{
	t_stack	*ptr;
	int		prev;

	ptr = *stack;
	if (ptr == NULL)
		return (1);
	if (ptr->next == NULL)
		return (1);
	prev = ptr->value;
	ptr = ptr->next;
	while (ptr != NULL)
	{
		if (prev > ptr->value)
			return (1);
		prev = ptr->value;
		ptr = ptr->next;
	}
	return (0);
}

int
	part_length(t_stack **stack, int part)
{
	int		i;
	t_stack	*ptr;

	i = 0;
	ptr = *stack;
	while (ptr && ptr->part == part)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

int
	count_parts(t_stack **stack)
{
	int		i;
	int		tmp;
	t_stack	*ptr;

	i = 0;
	tmp = -1;
	ptr = *stack;
	while (ptr)
	{
		if (ptr->part != tmp)
		{
			i++;
			tmp = ptr->part;
		}
		ptr = ptr->next;
	}
	return (1);
}

int
	new_part(t_stack **a_stack, t_stack **b_stack)
{
	int		tmp;
	t_stack	*ptr;

	tmp = -1;
	ptr = *a_stack;
	while (ptr)
	{
		if (tmp < ptr->part)
			tmp = ptr->part;
		ptr = ptr->next;
	}
	ptr = *b_stack;
	while (ptr)
	{
		if (tmp < ptr->part)
			tmp = ptr->part;
		ptr = ptr->next;
	}
	return (tmp + 1);
}