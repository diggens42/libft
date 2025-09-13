/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:34:49 by fwahl             #+#    #+#             */
/*   Updated: 2025/09/13 20:37:15 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned long ft_strtoul(const char *nptr, char **endptr, int base)
{
    const char *s = nptr;
    unsigned long acc;
    int c;
    unsigned long cutoff;
    int neg = 0;
    int any = 0;

    c = *s;
    while (ft_isspace(c))
        c = *++s;

    if (c == '-')
    {
        neg = 1;
        c = *++s;
    }
    else if (c == '+')
        c = *++s;

    if ((base == 0 || base == 16) && c == '0' && (*(s + 1) == 'x' || *(s + 1) == 'X'))
    {
        c = *++s;
        c = *++s;
        base = 16;
    }
    else if (base == 0)
    {
        if (c == '0')
            base = 8;
        else
            base = 10;
    }

    if (base < 2 || base > 36)
    {
        if (endptr)
            *endptr = (char *)nptr;
        return 0;
    }

    cutoff = (unsigned long)-1 / base;

    while (true)
    {
        if (ft_isdigit(c))
            c -= '0';
        else if (ft_isalpha(c))
            c -= (ft_isupper(c) ? 'A' - 10 : 'a' - 10);
        else
            break;

        if (c >= base)
            break;

        if (acc > cutoff)
            any = 1;
        else
        {
            acc *= base;
            acc += c;
            any = 1;
        }
        c = *++s;
    }

    if (endptr)
        *endptr = (char *)(any ? s : nptr);

    return (neg ? -acc : acc);
}
