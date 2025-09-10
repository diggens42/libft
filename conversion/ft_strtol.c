/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 00:30:17 by fwahl             #+#    #+#             */
/*   Updated: 2025/09/11 00:39:28 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long	ft_strtol(const char *str, char **endptr, int base)
{
    long            result;
    int             sign;
    const char      *s;
    unsigned long   cutoff;
    int             cutlim;
    int             any;

    s = str;
    result = 0;
    sign = 1;
    any = 0;

    while (ft_isspace(*s))
        s++;

    if (*s == '-')
    {
        sign = -1;
        s++;
    }
    else if (*s == '+')
        s++;

    if (base == 0)
    {
        if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        {
            base = 16;
            s += 2;
        }
        else if (s[0] == '0')
        {
            base = 8;
            s++;
        }
        else
            base = 10;
    }
    else if (base < 2 || base > 36)
    {
        if (endptr)
            *endptr = (char *)str;
        errno = EINVAL;
        return (0);
    }

    if (base == 16 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        s += 2;

    cutoff = (unsigned long)LONG_MAX / base;
    cutlim = (unsigned long)LONG_MAX % base;
    if (sign == -1)
    {
        cutoff = (unsigned long)LONG_MIN / base;
        cutlim = (unsigned long)LONG_MIN % base;
    }

    while (true)
    {
        int digit;

        if (ft_isdigit(*s))
            digit = *s - '0';
        else if (ft_toupper(*s) >= 'A' && ft_toupper(*s) <= 'Z')
            digit = ft_toupper(*s) - 'A' + 10;
        else
            break;
        if (digit >= base)
            break;
        if (sign == 1)
        {
            if (result > cutoff || (result == cutoff && digit > cutlim))
            {
                errno = ERANGE;
                if (endptr)
                    *endptr = (char *)s;
                return (LONG_MAX);
            }
        }
        else
        {
            if (result < cutoff || (result == cutoff && digit > -cutlim))
            {
                errno = ERANGE;
                if (endptr)
                    *endptr = (char *)s;
                return (LONG_MIN);
            }
        }

        result = result * base + digit * sign;
        s++;
        any = 1;
    }

    if (endptr)
    {
        if (any)
            *endptr = (char *)s;
        else
            *endptr = (char *)str;
    }

    return (result);
}