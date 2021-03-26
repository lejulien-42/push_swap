/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:11:15 by lejulien          #+#    #+#             */
/*   Updated: 2021/03/25 13:23:57 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char
    *ft_itoa2(int is_zero, unsigned int nu, int i)
{
    char    *res;

    if (!(res = malloc((i + 1) * sizeof(char))))
        return (NULL);
    res[i] = '\0';
    while (nu > 0)
    {
        i--;
        res[i] = nu % 10 + '0';
        nu = nu / 10;
    }
    i--;
    if (is_zero)
    {
        res[i] = nu + '0';
        i--;
    }
    if (i == 0)
        res[i] = '-';
    return (res);
}

char
    *ft_itoa(int n)
{
    unsigned int    nu;
    int             i;
    int             is_zero;

    i = 0;
    if (n <= 0)
    {
        nu = -n;
        i++;
    }
    else
        nu = n;
    is_zero = 0;
    while (n != 0)
    {
        n = n / 10;
        i++;
    }
    if (nu == 0)
        is_zero++;
    return (ft_itoa2(is_zero, nu, 1));
}