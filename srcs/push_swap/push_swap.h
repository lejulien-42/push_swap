/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:24:17 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/27 13:58:42 by lejulien         ###   ########.fr       */
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
int		part_length(t_stack **stack, int part);
void	quick_sort(t_stack **a_stack, t_stack **b_stack);
int		count_parts(t_stack **stack);
void	ft_puterror(char *str);
int		new_part(t_stack **a_stack, t_stack **b_stack);
void	debug_stack(t_stack **stack, char *str);
int		is_part_in_stack(t_stack **stack, int part);
int		r_check_stack(t_stack **stack);
void	sort(t_stack **a_stack, t_stack **b_stack);
int		smallest(t_stack **stack);
int		biggest(t_stack **stack);
void	move_top(int val, t_stack **stack);
void	print_val(char *str, int val);
int		val_pos(int val, t_stack **stack);
int		is_val_in_part(t_stack **stack, int val, int part);
void	stack_dup(t_stack **res, t_stack **src);
void	ft_free_stack(t_stack **stack);
void	chunked(t_stack **stack, int nbr);
void	sort_chunck(t_stack **a_stack, t_stack **b_stack, t_stack **test_stack, int nbr);
void	go_max(t_stack**b_stack, int part);
int		get_last_val(t_stack **stack);
#endif
