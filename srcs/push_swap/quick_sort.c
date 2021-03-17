/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:03:35 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/17 09:48:14 by lejulien         ###   ########.fr       */
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
    part_parta(t_stack **a_stack, t_stack **b_stack, int part, int new_party)
{
    int     length;
    int     i;
    t_stack *ptr1;
    t_stack *ptr2;

    i = 0;
    length = part_length(a_stack, part);
    while (i < length - 1)
    {
        ptr1 = *a_stack;
        ptr2 = ptr1->next;
        if (!ptr2 || ptr2->part != part)
            return ;
        swap(a_stack);
        ft_putstr("sa\n");
        ptr1 = *a_stack;
        ptr2 = ptr1->next;
        if (ptr1->value > ptr2->value && ptr1->part == ptr2->part)
        {
            ptr1->part = new_party;
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
    ptr1 = *a_stack;
    ptr1->part = new_part(a_stack, b_stack) + 1;
    ptr1 = *b_stack;
    while (ptr1 && ptr1->part == new_party)
    {
        push(b_stack, a_stack);
        ft_putstr("pa\n");
        ptr1 = *b_stack;
    }
    ptr1 = *a_stack;
    while (ptr1 && (ptr1->part == new_party || ptr1->part == new_party + 1))
    {
        rotate(a_stack);
        ft_putstr("ra\n");
        ptr1 = *a_stack;
    }
}

static void
    quick_sort_a(t_stack **a_stack, t_stack **b_stack)
{
    int     part;
    t_stack *ptr1;
    t_stack *ptr2;

    while (check_stack(a_stack))
    {
        ptr1 = *a_stack;
        ptr2 = ptr1->next;
        if (ptr1)
            part = ptr1->part;
        if (ptr2 && ptr2->part == part)
        {
            part_parta(a_stack, b_stack, part, new_part(a_stack, b_stack));
        }
        ptr1 = *a_stack;
        while (part_length(a_stack, ptr1->part) <= 1)
        {
            rotate(a_stack);
            ft_putstr("ra\n");
            ptr1 = *a_stack;
        }

    }
}

void
    quick_sort(t_stack **a_stack, t_stack **b_stack)
{
    partitioning(a_stack, b_stack);
    quick_sort_a(a_stack, b_stack);
}