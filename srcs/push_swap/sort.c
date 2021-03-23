/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:32:28 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/23 16:52:54 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../utils/utils.h"
#include <stdlib.h>

static void
    sort_3(t_stack **a_stack)
{
    t_stack *ptr;

    ptr = *a_stack;
    if (ptr->next->value < ptr->value && ptr->value < ptr->next->next->value)
    {
        swap(a_stack);
        ft_putstr("sa\n");
    }
    else if (ptr->value > ptr->next->value && ptr->next->value > ptr->next->next->value)
    {
        swap(a_stack);
        ft_putstr("sa\n");
        r_rotate(a_stack);
        ft_putstr("rra\n");
    }
    else if (ptr->next->value < ptr->next->next->value && ptr->next->next->value < ptr->value)
    {
        rotate(a_stack);
        ft_putstr("ra\n");
    }
    else if (ptr->value < ptr->next->next->value && ptr->next->next->value < ptr->next->value)
    {
        swap(a_stack);
        ft_putstr("sa\n");
        rotate(a_stack);
        ft_putstr("ra\n");
    }
    else if (ptr->next->next->value < ptr->value && ptr->value < ptr->next->value)
    {
        r_rotate(a_stack);
        ft_putstr("rra\n");
    }
}

static void
    sort_5(t_stack **a_stack, t_stack **b_stack)
{
    t_stack *ptr1;
    t_stack *ptr2;
    int     start;

    push(a_stack, b_stack);
    ft_putstr("pb\n");
    push(a_stack, b_stack);
    ft_putstr("pb\n");
    if (check_stack(a_stack))
        sort_3(a_stack);
    ptr1 = *a_stack;
    ptr2 = *b_stack;
    if (ptr2->value < ptr1->value)
    {
        push(b_stack, a_stack);
        ft_putstr("pa\n");
    }
    else
    {
        ptr1 = *a_stack;
        ptr2 = *b_stack;
        start = ptr1->value;
        if (ptr1->value < ptr2->value)
        {
            rotate(a_stack);
            ft_putstr("ra\n");
            ptr1 = *a_stack;
        }
        while (ptr1->value < ptr2->value && ptr1->value != start)
        {
            rotate(a_stack);
            ft_putstr("ra\n");
            ptr1 = *a_stack;
        }
        push(b_stack, a_stack);
        ft_putstr("pa\n");
    }
    while (check_stack(a_stack))
    {
        rotate(a_stack);
        ft_putstr("ra\n");
    }
    // COPPY

    ptr1 = *a_stack;
    ptr2 = *b_stack;
    if (ptr2->value < ptr1->value)
    {
        push(b_stack, a_stack);
        ft_putstr("pa\n");
    }
    else
    {
        ptr1 = *a_stack;
        ptr2 = *b_stack;
        start = ptr1->value;
        if (ptr1->value < ptr2->value)
        {
            rotate(a_stack);
            ft_putstr("ra\n");
            ptr1 = *a_stack;
        }
        while (ptr1->value < ptr2->value && ptr1->value != start)
        {
            rotate(a_stack);
            ft_putstr("ra\n");
            ptr1 = *a_stack;
        }
        push(b_stack, a_stack);
        ft_putstr("pa\n");
    }
    while (check_stack(a_stack))
    {
        rotate(a_stack);
        ft_putstr("ra\n");
    }
}

static void
    ins_sort(t_stack **a_stack, t_stack **b_stack)
{
    while (*a_stack != NULL)
    {
        move_top(smallest(a_stack), a_stack);
        if (smallest(a_stack) != -4 && val_pos(smallest(a_stack), a_stack) < (part_length(a_stack, 0) / 2))
        {
            debug_stack(a_stack);
            return ;
        }
        push(a_stack, b_stack);
        ft_putstr("pb\n");
    }
}

void
    sort(t_stack **a_stack, t_stack **b_stack)
{
    if (part_length(a_stack, 0) == 3)
    {
        sort_3(a_stack);
    }
    else if (part_length(a_stack, 0) == 5)
    {
        sort_5(a_stack, b_stack);
    }
    ins_sort(a_stack, b_stack);
}