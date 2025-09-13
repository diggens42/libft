/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_substract.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 03:58:53 by fwahl             #+#    #+#             */
/*   Updated: 2025/09/13 04:05:46 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Subtract two timevals: result = a - b
void ft_time_substract(struct timeval *result, struct timeval *a, struct timeval *b)
{
    result->tv_sec = a->tv_sec - b->tv_sec;
    result->tv_usec = a->tv_usec - b->tv_usec;

    if (result->tv_usec < 0)
    {
        result->tv_sec--;
        result->tv_usec += 1000000;
    }
}