/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:24:17 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/15 19:10:27 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H



typedef struct		s_stack
{
	int				value;
	int				disp;
	int				part;
	struct s_stack	*next;
}					t_stack;

int		add_to_stack(t_stack **stack, int value, int pos);
int		ft_free_stacks(t_stack **a_stack, t_stack **b_stack, int ret);
void	display_stack(t_stack **a_stack, t_stack **b_stack);
int		has_double(t_stack **stack);
int		entry(t_stack **a_stack, t_stack **b_stack);
void	push(t_stack **a_stack, t_stack **b_stack);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	r_rotate(t_stack **stack);
int		check_stack(t_stack **stack);
void	bubble_sort(t_stack **stack, int nbr);
#endif
