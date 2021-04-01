/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:38:15 by lejulien          #+#    #+#             */
/*   Updated: 2021/04/01 18:24:46 by lejulien         ###   ########.fr       */
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

int				add_to_stack(t_stack **stack, int value, int pos);
int				ft_free_stacks(t_stack **a_stack, t_stack **b_stack, int ret);
void			display_stack(t_stack **a_stack, t_stack **b_stack);
int				has_double(t_stack **stack);
int				entry(t_stack **a_stack, t_stack **b_stack);
void			push(t_stack **a_stack, t_stack **b_stack);
void			swap(t_stack **stack);
void			rotate(t_stack **stack);
void			r_rotate(t_stack **stack);
void			check_stack(t_stack **stack);
int				push_values_to_stack(t_stack **stack, char **av, int ac,
				int pos);
int				check_flags(int ac, char **av);
int				check_num(int ac, char **av);
int				check_max(int ac, char **av);
int				parse_entry(char *str, t_stack **a_stack, t_stack **b_stack);
int				ft_strlen(char *str);
#endif
