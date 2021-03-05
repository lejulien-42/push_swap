/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:38:15 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/05 19:36:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

typedef struct	s_stack
{
	int		value;
	int		disp;
	void	*next;
}				t_stack;

int		add_to_stack(t_stack **stack, int value, int pos);
int		ft_free_stacks(t_stack **a_stack, t_stack **b_stack, int ret);
void	display_stack(t_stack **a_stack, t_stack **b_stack);
#endif
