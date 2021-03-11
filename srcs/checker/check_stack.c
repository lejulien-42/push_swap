#include "checker.h"
#include <stdlib.h>
#include "../utils/utils.h"

void
	check_stack(t_stack **stack)
{
	t_stack	*ptr;
	int		prev;

	ptr = *stack;
	if (ptr == NULL)
	{
		ft_putstr("KO\n");
		return ;
	}
	if (ptr->next == NULL)
	{
		ft_putstr("OK\n");
		return ;
	}
	prev = ptr->value;
	ptr = ptr->next;
	while (ptr->next != NULL)
	{
		if (prev > ptr->value)
		{
			ft_putstr("KO\n");
			return ;
		}
		prev = ptr->value;
		ptr = ptr->next;
	}
	ft_putstr("OK\n");
}
