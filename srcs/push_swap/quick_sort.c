/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:03:35 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/18 19:02:13 by lejulien         ###   ########.fr       */
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
    
    while (check_stack(a_stack))
    {
        p_next = new_part(a_stack, b_stack);
        ptr = *a_stack;
        if (part_length(a_stack, ptr->part) > 1)
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
        }
        else
        {
            rotate(a_stack);
            ft_puterror("sa\n");
        }
        ptr = *b_stack;
        while (ptr->part == p_next)
        {
            ptr = *b_stack;
            push(b_stack, a_stack);
            ft_putstr("pa\n");
        }
        ptr = *a_stack;
        while (ptr->part == p_next)
        {
            ptr = *a_stack;
            rotate(a_stack);
            ft_putstr("ra\n");
        }
    }
}

void
    quick_sort(t_stack **a_stack, t_stack **b_stack)
{
    partitioning(a_stack, b_stack);
    quick_sort_a(a_stack, b_stack);
}