/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:38:15 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/05 17:06:56 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

typedef struct	s_stack
{
	int		value;
	void	*next;
}				t_stack;

int		add_to_stack(t_stack *stack, int value);
void	ft_free_stacks(t_stack **a_stack, t_stack **b_stack, int ret);
#endif
