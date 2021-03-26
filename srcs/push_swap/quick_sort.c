/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:03:35 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/26 13:06:43 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../utils/utils.h"
#include <stdlib.h>

static void
    partitioning(t_stack **a_stack, t_stack **b_stack)
{
    int     length;
    int     i;
    t_stack *ptr1;
    t_stack *ptr2;

    i = 0;
    length = part_length(a_stack, 0);
    while (i < length - 1)
    {
        ptr1 = *a_stack;
        ptr2 = ptr1->next;
        if (ptr2 && ptr1->part == ptr2->part)
        {
            swap(a_stack);
            ft_putstr("sa\n");
            ptr1 = *a_stack;
            ptr2 = ptr1->next;
        }
        if (ptr2 == NULL)
            return ;
        if (ptr1->part == ptr2->part && ptr1->value < ptr2->value)
        {
            ptr1->part = 1;
            push(a_stack, b_stack);
            ft_putstr("pb\n");
        }
        else
        {
            rotate(a_stack);
            ft_putstr("ra\n");
        }
        i++;
    }
}

static void
    quick_sort_a(t_stack **a_stack, t_stack **b_stack)
{
    t_stack *ptr;
    t_stack *ptr2;
    int     p_next;
    int     p_length;

    p_next = new_part(a_stack, b_stack);
    ptr = *a_stack;
    p_length = part_length(a_stack, ptr->part);
    while (p_length > 1)
    {
        swap(a_stack);
        ft_putstr("sa\n");
        ptr = *a_stack;
        ptr2 = ptr->next;
        if (ptr->value > ptr2->value)
        {
            ptr->part = p_next;
            push(a_stack, b_stack);
            ft_putstr("pb\n");
        }
        else
        {
            rotate(a_stack);
            ft_putstr("ra\n");
        }
        p_length--;
    }
    rotate(a_stack);
    ft_putstr("ra\n");
    ptr = *b_stack;
    while (ptr && ptr->part == p_next)
    {
        push(b_stack, a_stack);
        ft_putstr("pa\n");
        ptr = *b_stack;
    }
    ptr = *a_stack;
    while (ptr && ptr->part == p_next)
    {
        rotate(a_stack);
        ft_putstr("ra\n");
        ptr = *a_stack;
    }
    if (check_stack(a_stack))
        quick_sort_a(a_stack, b_stack);
}

static void
    quick_sort_b(t_stack **a_stack, t_stack **b_stack)
{
    t_stack *ptr;
    t_stack *ptr2;
    int     p_next;
    int     p_length;
    p_next = new_part(b_stack, a_stack);
    ptr = *b_stack;
    p_length = part_length(b_stack, ptr->part);
    while (p_length > 1)
    {
        swap(b_stack);
        ft_putstr("sb\n");
        ptr = *b_stack;
        ptr2 = ptr->next;
        if (ptr->value < ptr2->value)
        {
            ptr->part = p_next;
            push(b_stack, a_stack);
            ft_putstr("pa\n");
        }
        else
        {
            rotate(b_stack);
            ft_putstr("rb\n");
        }
        p_length--;
    }
    rotate(b_stack);
    ft_putstr("rb\n");
    ptr = *a_stack;
    while (ptr && ptr->part == p_next)
    {
        push(a_stack, b_stack);
        ft_putstr("pb\n");
        ptr = *a_stack;
    }
    ptr = *b_stack;
    while (ptr && ptr->part == p_next)
    {
        rotate(b_stack);
        ft_putstr("rb\n");
        ptr = *b_stack;
    }
    if (r_check_stack(b_stack))
        quick_sort_b(a_stack, b_stack);
}

void
    quick_sort(t_stack **a_stack, t_stack **b_stack)
{
    t_stack *ptr;

    partitioning(a_stack, b_stack);
    quick_sort_a(a_stack, b_stack);
    quick_sort_b(a_stack, b_stack);
    ptr = *b_stack;
    while (ptr)
    {
        push(b_stack, a_stack);
        ft_putstr("pa\n");
        if (*b_stack)
            ptr = *b_stack;
        else
            ptr = NULL;
    }
    debug_stack(b_stack);
}
