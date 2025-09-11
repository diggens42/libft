/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 02:15:49 by fwahl             #+#    #+#             */
/*   Updated: 2025/09/11 02:21:07 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double ft_strtod(const char *str, char **endptr)
{
    double res = 0.0;
    double fract = 0.0;
    int sign = 1;
    int exp = 0;
    int i = 0;

    while (ft_isspace(str[i]))
        i++;

    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;

    while (ft_isdigit(str[i]))
    {
        res = res * 10.0 + (str[i] - '0');
        i++;
    }

    if (str[i] == '.')
    {
        i++;
        double div = 10.0;
        while (ft_isdigit(str[i]))
        {
            fract += (str[i] - '0') / div;
            div *= 10.0;
            i++;
        }
    }

    res += fract;

    if (str[i] == 'e' || str[i] == 'E')
    {
        i++;
        int exp_sign = 1;
        
        if (str[i] == '-')
        {
            exp_sign = -1;
            i++;
        }
        else if (str[i] == '+')
            i++;
        int exp_val = 0;
        while (ft_isdigit(str[i]))
        {
            exp_val = exp_val * 10 + (str[i] - '0');
            i++;
        }
        exp = exp_sign * exp_val;
    }

    res *= ft_pow(10.0, exp);

    if (endptr != NULL)
        *endptr = (char *)(str + i);

    return (sign * res);
}
