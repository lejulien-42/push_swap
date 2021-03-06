/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:06:31 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/31 16:01:35 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr(const char *str);
float	ft_sqrt(float nb);
int		my_strcmp(char *s1, char *s2);
#endif
