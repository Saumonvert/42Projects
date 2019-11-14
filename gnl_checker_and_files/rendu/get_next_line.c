/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:09:29 by dsy               #+#    #+#             */
/*   Updated: 2019/11/14 16:05:31 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		free_buffer(void **buf)
{
	free(*buf);
	return (0);
}

int		setup_next_line(char **l_stack, char **line)
{
	int	i;

	i = 0;
	while ((*l_stack)[i] != '\n')
	{
		if ((*l_stack)[i] == '\0')
			return (0);
		i++;
	}
	(*l_stack)[i] = '\0';
	*line = ft_strdup(*l_stack);
	*l_stack = ft_strdup((*l_stack) + i + 1);
	return (1);
}

int		gnl_read(int fd, char *file_read, char **l_stack, char **line)
{
	int	bytes;

	while ((bytes = read(fd, file_read, BUFFER_SIZE)) > 0)
	{
		file_read[bytes] = '\0';
		if (*l_stack)
			*l_stack = ft_strjoin(*l_stack, file_read);
		else
			*l_stack = ft_strdup(file_read);
		if (setup_next_line(l_stack, line))
			break ;
	}
	return (bytes < 0 ? -bytes : bytes);
}

int		get_next_line(int const fd, char **line)
{
	static char		*l_stack[MAX_FD];
	char			*file_read;
	int				ret;
	int				i;

	if (!line || (fd < 0 || fd >= MAX_FD) || (read(fd, l_stack[fd], 0) < 0) \
			|| !(file_read = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (l_stack[fd])
		if (setup_next_line(&l_stack[fd], line))
			return (free_buffer(&file_read) + 1);
	i = 0;
	while (i < BUFFER_SIZE)
		file_read[i++] = '\0';
	ret = gnl_read(fd, file_read, &l_stack[fd], line);
	free(file_read);
	if (ret != 0 || l_stack[fd] == NULL || l_stack[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret <= 0 ? ret : 1);
	}
	*line = l_stack[fd];
	l_stack[fd] = NULL;
	return (1);
}
