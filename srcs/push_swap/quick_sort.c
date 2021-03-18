/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:03:35 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/18 17:14:47 by lejulien         ###   ########.fr       */
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

void
    quick_sort(t_stack **a_stack, t_stack **b_stack)
{
    partitioning(a_stack, b_stack);
}