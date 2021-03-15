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
		{
			return (1);
		}
		prev = ptr->value;
		ptr = ptr->next;
	}
	return (0);
}
