/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_substract.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:01:37 by fwahl             #+#    #+#             */
/*   Updated: 2026/05/28 16:25:17 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Subtract two timevals: result = a - b
// void ft_time_substract(struct timeval *result, struct timeval *a,
// struct timeval *b)
// {
//     result->tv_sec = a->tv_sec - b->tv_sec;
//     result->tv_usec = a->tv_usec - b->tv_usec;

//     if (result->tv_usec < 0)
//     {
//         result->tv_sec--;
//         result->tv_usec += 1000000;
//     }
// }
