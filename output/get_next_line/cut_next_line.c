/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:02:20 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/11 19:16:47 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	cut_next_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isnextline(line[i]) == true)
		{
			line[i] = '\0';
			break ;
		}
		i++;
	}
}
