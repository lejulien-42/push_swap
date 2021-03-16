#include "checker.h"
#include "../utils/utils.h"
#include <stdlib.h>
#include <unistd.h>

static void
	stack_header()
{
	ft_putstr("---------------------\n| stack A | stack B |\n");
	ft_putstr("---------------------\n");
}

static void
	ft_print_value(int val, int aorb)
{
	int	buffer;
	int	size;
	int isneg;

	size = 0;
	isneg = 0;
	buffer = val;
	if (val == 0)
		size = 1;
	if (val < 0)
	{
		size += 2;
		isneg = 1;
		val = val * (-1);
	}
	while (buffer > 0)
	{
		buffer = buffer  / 10;
		size++;
	}
	if (aorb)
		ft_putstr("\e[45m");
	else
		ft_putstr("\e[42m");
	if (isneg)
		write(1, "-", 1);
	ft_putnbr_fd(val, 1);
	while (size < 7)
	{
		ft_putstr(" ");
		size++;
	}
	ft_putstr("\e[49m");
}

void
	display_stack(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*ptr_a;
	t_stack	*ptr_b;

	ptr_a = *a_stack;
	ptr_b = *b_stack;
	ft_putstr("\e[49m");
	while (ptr_a != NULL || ptr_b != NULL)
	{
		ft_putstr("---------------------\n| ");
		if (ptr_a != NULL)
			ft_print_value(ptr_a->value, 1);
		else
			ft_putstr("       ");
		ft_putstr(" | ");
		if (ptr_b != NULL)
			ft_print_value(ptr_b->value, 0);
		else
			ft_putstr("       ");
		if (ptr_a != NULL)
			ptr_a = ptr_a->next;
		if (ptr_b != NULL)
			ptr_b = ptr_b->next;
		ft_putstr(" |\n");
	}
	stack_header();
}
