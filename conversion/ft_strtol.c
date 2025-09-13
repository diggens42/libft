/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 00:30:17 by fwahl             #+#    #+#             */
/*   Updated: 2025/09/13 19:57:43 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long ft_strtol(const char *str, char **endptr, int base)
{
    unsigned long   acc = 0;
    unsigned long   cutoff;
    int             cutlim;
    int             sign = 1;
    const char      *s = str;
    int             any = 0;

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
        if (endptr) *endptr = (char *)str;
        errno = EINVAL;
        return 0;
    }

    if (base == 16 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        s += 2;

    cutoff = (sign > 0) ? LONG_MAX : -(unsigned long)LONG_MIN;
    cutlim = cutoff % base;
    cutoff /= base;

    while (*s)
    {
        int digit;

        if (ft_isdigit(*s))
            digit = *s - '0';
        else if (ft_isalpha(*s))
            digit = ft_toupper(*s) - 'A' + 10;
        else
            break;

        if (digit >= base)
            break;

        if (acc > cutoff || (acc == cutoff && (unsigned)digit > (unsigned)cutlim))
        {
            errno = ERANGE;
            return (sign > 0) ? LONG_MAX : LONG_MIN;
        }

        acc = acc * base + digit;
        any = 1;
        s++;
    }


    if (endptr)
        *endptr = (char *)(any ? s : str);

    return ((sign > 0) ? (long)acc : -(long)acc);
}
