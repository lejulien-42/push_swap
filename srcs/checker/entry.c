#include "checker.h"
#include "../utils/utils.h"
#include <unistd.h>

int
	entry(t_stack **a_stack, t_stack **b_stack)
{
	int		run;
	char	c;
	t_stack	*a_ptr;
	t_stack	*b_ptr;

	a_ptr = *a_stack;
	b_ptr = *b_stack;
	run = 1;
	while (run)
	{
		if (read(1, &c, 1) == 0)
			run = 0;
		if (c == '\n')
		{
			//do process;
			if (a_ptr != NULL)
			{
				if (a_ptr->disp == 2)
					display_stack(a_stack, b_stack);
			}
		}
	}
	return (0);
}
