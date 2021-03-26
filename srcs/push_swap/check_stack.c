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
	r_check_stack(t_stack **stack)
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
		if (prev < ptr->value)
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

void
	print_val(char *str, int val)
{
	ft_puterror(str);
	ft_putnbr_fd(val, 2);
	ft_puterror("\n");
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

int
	smallest(t_stack **stack)
{
	t_stack *ptr;
	int		val;

	ptr = *stack;
	val = ptr->value;
	ptr = ptr->next;
	while (ptr)
	{
		if (ptr->value < val)
			val = ptr->value;
		ptr = ptr->next;
	}
	return (val);
}

int
	biggest(t_stack **stack)
{
	t_stack *ptr;
	int		val;

	ptr = *stack;
	val = ptr->value;
	ptr = ptr->next;
	while (ptr)
	{
		if (ptr->value > val)
			val = ptr->value;
		ptr = ptr->next;
	}
	return (val);
}

int
	val_pos(int val, t_stack **stack)
{
	int		i;
	t_stack	*ptr;

	i = 0;
	ptr = *stack;
	while (ptr)
	{
		if (val == ptr->value)
			return (i);
		i++;
		ptr = ptr->next;
	}
	return (-1);
}

void
	move_top(int val, t_stack **stack)
{
	int		length;
	int		pos;

	length = part_length(stack, 0);
	if (pos < (length / 2))
	{
		print_val("val = ", val);
		while (pos <= (length / 2))
		{
			rotate(stack);
			ft_putstr("ra\n");
			pos++;
		}
	}
	else
	{
		while (pos < length)
		{
			r_rotate(stack);
			ft_putstr("rra\n");
			pos++;
		}
	}
	
}

int
	is_val_in_part(t_stack **stack, int val, int part)
{
	t_stack	*ptr;

	ptr = *stack;
	while (ptr && ptr->part != part)
		ptr = ptr->next;
	while (ptr && ptr->part == part)
	{
		if (ptr->value == val)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

static int
	get_max(t_stack	**b_stack)
{
	t_stack	*ptr;
	int		max;

	if (!*b_stack)
		return (-1);
	ptr = *b_stack;
	max = ptr->value;
	ptr = ptr->next;
	while (ptr)
	{
		if (ptr->value > max)
			max = ptr->value;
		ptr = ptr->next;
	}
	return (max);
}

// here

void
	go_max(t_stack**b_stack, int part)
{
	t_stack	*ptr;

	ptr = *b_stack;
	if (!*b_stack)
		return ;
	ft_putnbr_fd(get_max(b_stack), 2);
	return ;
	while (ptr->value != get_max(b_stack))
	{
		rotate(b_stack);
		ft_putstr("rb\n");
		ptr = *b_stack;
	}
}
