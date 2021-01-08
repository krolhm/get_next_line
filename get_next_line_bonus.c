/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:35:48 by rbourgea          #+#    #+#             */
/*   Updated: 2019/11/22 16:35:50 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	newline(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int			get_next_line(int fd, char **line)
{
	int				r;
	static char		buffer[4096][BUFFER_SIZE + 1];

	if (!line || fd < 0)
		return (-1);
	if (BUFFER_SIZE == 0)
	{
		*line = 0;
		return (-1);
	}
	*line = ft_strdup("", 0);
	while (newline(buffer[fd]) == -1)
	{
		if (!(*line = ft_strjoin(*line, buffer[fd], '\n')))
			return (-1);
		ft_bzero(buffer[fd], BUFFER_SIZE + 1);
		r = read(fd, buffer[fd], BUFFER_SIZE);
		if (r <= 0)
			return (r);
	}
	if (!(*line = ft_strjoin(*line, buffer[fd], '\n')))
		return (-1);
	ft_strlcpy(buffer[fd], buffer[fd] + newline(buffer[fd]) + 1, BUFFER_SIZE);
	return (1);
}
