/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:21:14 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/11 13:31:38 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H



typedef struct	s_stack
{
	int		value;
	int		disp;
	void	*next;
}				t_stack;

int		add_to_stack(t_stack **stack, int value, int pos);
int		ft_free_stacks(t_stack **a_stack, t_stack **b_stack, int ret);
int		entry(t_stack **a_stack, t_stack **b_stack);
void	push(t_stack **a_stack, t_stack **b_stack);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	r_rotate(t_stack **stack);
void	check_stack(t_stack **stack);
int		has_double(t_stack **stack);
#endif
