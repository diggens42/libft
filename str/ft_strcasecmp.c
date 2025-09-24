/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:01:37 by fwahl             #+#    #+#             */
/*   Updated: 2025/09/24 17:02:13 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int ft_strcasecmp(const char *s1, const char *s2)
{
    unsigned char c1, c2;

    if (!s1 || !s2)
        return (s1 - s2);
    while (*s1 && *s2)
    {
        c1 = (unsigned char)ft_tolower(*s1);
        c2 = (unsigned char)ft_tolower(*s2);
        if (c1 != c2)
            return (c1 - c2);
        s1++;
        s2++;
    }
    c1 = (unsigned char)ft_tolower(*s1);
    c2 = (unsigned char)ft_tolower(*s2);
    return (c1 - c2);
}
