/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:03:35 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/16 18:42:37 by lejulien         ###   ########.fr       */
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
        swap(a_stack);
        ft_putstr("sa\n");
        ptr1 = *a_stack;
        ptr2 = ptr1->next;
        if (ptr2 == NULL)
            return ;
        if (ptr1->value < ptr2->value)
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
    part_parta(t_stack **a_stack, t_stack **b_stack, int part, int new_part)
{
    int     length;
    int     i;
    t_stack *ptr1;
    t_stack *ptr2;

    i = 0;
    length = part_length(a_stack, part);
    while (i < length -2)
    {
        ptr1 = *a_stack;
        ptr2 = ptr1->next;
        if (!ptr2 || ptr2->part != part)
            return ;
        swap(a_stack);
        ft_putstr("sa\n");
        ptr1 = *a_stack;
        ptr2 = ptr1->next;
        if (ptr1->value > ptr2->value)
        {
            ptr1->part = new_part;
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
    ptr1 = *b_stack;
    while (ptr1 && ptr1->part == new_part)
    {
        push(b_stack, a_stack);
        ft_putstr("pa\n");
        ptr1 = *b_stack;
    }
}

static void
    quick_sort_a(t_stack **a_stack, t_stack **b_stack)
{
    int     part;
    int     parts;
    t_stack *ptr1;
    t_stack *ptr2;

    while (check_stack(a_stack))
    {
        parts = count_parts(a_stack);
        ptr1 = *a_stack;
        ptr2 = ptr1->next;
        if (ptr1)
            part = ptr1->part;
        if (ptr2 && ptr2->part == part)
            part_parta(a_stack, b_stack, part, new_part(a_stack, b_stack));
        else
        {
            rotate(a_stack);
            ft_putstr("ra\n");
        }
        ft_puterror("Here ?\n");
    }
}

void
    quick_sort(t_stack **a_stack, t_stack **b_stack)
{
    partitioning(a_stack, b_stack);
    quick_sort_a(a_stack, b_stack);
}