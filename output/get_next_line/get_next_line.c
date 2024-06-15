/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:02:24 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/15 17:59:08 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif
#define ERROR -2

static long	find_buffer_eol(char *buffer)
{
	long	i;

	i = 0;
	if (ft_isnextline(buffer[0]))
		return (1);
	while (i < BUFFER_SIZE && buffer[i] && !ft_isnextline(buffer[i]))
		i++;
	if (i < BUFFER_SIZE && ft_isnextline(buffer[i]))
		i++;
	return (i);
}

static long	realloc_line(long len, char **line)
{
	long	old_len;
	char	*new_line;

	old_len = ft_strlen(*line);
	new_line = ft_calloc(old_len + len + 1, sizeof(char));
	if (new_line == NULL)
		return (ERROR);
	ft_memcpy(new_line, *line, old_len);
	free(*line);
	*line = new_line;
	return (old_len);
}

static int	alloc_line(char **line, long len)
{
	int	offset;

	offset = 0;
	if (*line == NULL)
	{
		*line = ft_calloc((len + 1), sizeof(char));
		if (*line == NULL)
			return (ERROR);
	}
	else
		offset = realloc_line(len, line);
	return (offset);
}

static long	copy_line_to_buffer(char **line, char *buffer, long len)
{
	long	i;
	long	offset;

	offset = alloc_line(line, len);
	if (offset == ERROR)
		return (ERROR);
	i = 0;
	while (i <= len && i < BUFFER_SIZE && buffer[i])
	{
		(*line)[offset + i] = buffer[i];
		if (ft_isnextline(buffer[i++]))
			break ;
	}
	if (ft_isnextline((*line)[i + offset - 1]))
		len = -1;
	return (len);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	long		len;
	int			nbytes;

	line = NULL;
	nbytes = read(fd, buffer, BUFFER_SIZE);
	while (nbytes > 0 || buffer[0])
	{
		if (nbytes < 0)
			return (NULL);
		len = find_buffer_eol(buffer);
		len = copy_line_to_buffer(&line, buffer, len);
		if (len < 0)
		{
			if (len == ERROR && line)
				free(line);
			break ;
		}
		if (buffer[0] == '\0')
			nbytes = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}
