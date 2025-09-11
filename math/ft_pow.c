/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 02:09:53 by fwahl             #+#    #+#             */
/*   Updated: 2025/09/11 02:14:17 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double ft_pow(double base, int exp)
{
    double  res;
    int     sign;

    res = 1.0;
    sign = 1;
    if (exp < 0)
    {
        sign = -1;
        exp = -exp;
    }
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res *= base;
        base *= base;
        exp /= 2;
    }
    if (sign == -1)
        res = 1.0 / res;
    return (res);
}
