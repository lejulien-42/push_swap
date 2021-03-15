/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:15:08 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/15 20:00:43 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include "../utils/utils.h"

static int
    stack_length(t_stack **stack)
{
    int     i;
    t_stack *ptr;

    i = 0;
    ptr = *stack;
    while (ptr)
    {
        i++;
        ptr = ptr->next;
    }
    return (i);
}

static void
    partitionning(t_stack **a_stack, t_stack **b_stack)
{
    int     i;
    t_stack *ptr1;
    t_stack *ptr2;

    i = 0;
    while (i < (stack_length(a_stack) + 2))
    {
        ptr1 = *a_stack;
        ptr2 = ptr1->next;
        if (ptr1->next == NULL)
            return ;
        swap(a_stack);
        ft_putstr("sa\n");
        ptr1 = *a_stack;
        ptr2 = ptr1->next;
        if (ptr1->value < ptr2->value)
        {
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
    partitionning(a_stack, b_stack);
}