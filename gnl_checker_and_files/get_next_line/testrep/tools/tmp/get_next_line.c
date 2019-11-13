/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:09:29 by dsy               #+#    #+#             */
/*   Updated: 2019/11/13 06:16:45 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
/*
int		ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s);
	if (!s)
		return (NULL);
	if (!(newstr = malloc(sizeof(char) * j)))
		return (NULL);
	while (i < j)
	{
		newstr[i] = s[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	j = 0;
	n = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !(newstr = (char*)malloc(sizeof(char) *
				   n + 1)))
		return (NULL);
	n = ft_strlen(s1);
	while (i < n)
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*dest;

	dest = s;
	i = 0;
	while (i < (unsigned char)n)
	{
		dest[i] = 0;
		i++;
	}
}
*/
int		setup_next_line(char **line_stack, char **line)
{
	int	i;

	i = 0;
	while ((*line_stack)[i] != '\n')
	{
		if ((*line_stack)[i] == '\0')
			return (0);
		i++;
	}
	(*line_stack)[i] = '\0';
	*line = ft_strdup(*line_stack);
	ft_bzero(*line_stack, i);
	*line_stack = ft_strdup((*line_stack) + i + 1);
	return (1);
}

int		gnl_read(int fd, char *file_content, char **line_stack, char **line)
{
	int	bytes;

	while ((bytes = read(fd, file_content, BUFFER_SIZE)) > 0)
	{
		file_content[bytes] = '\0';
		if (*line_stack)
			*line_stack = ft_strjoin(*line_stack, file_content);
		else
			*line_stack = ft_strdup(file_content);
		if (setup_next_line(line_stack, line))
			break ;
	}
//	if (bytes == BUFFER_SIZE && !line_stack)
//		*line_stack = ft_strdup(file_content);
	return (bytes == 0 ? 0 : 1);
}

int					get_next_line(int const fd, char **line)
{
	static char		*stack[MAX_FD];
	char			*heap;
	int				ret;
	int				i;

	if (!line || (fd < 0 || fd >= MAX_FD) || (read(fd, stack[fd], 0) < 0) \
		|| BUFFER_SIZE < 1 || !(heap = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (stack[fd])
		if (setup_next_line(&stack[fd], line))
		{
			free(heap);
			return (1);
		}
	i = 0;
	while (i < BUFFER_SIZE)
		heap[i++] = '\0';
	ret = gnl_read(fd, heap, &stack[fd], line);
	free(heap);
	if (ret != 0 || stack[fd] == NULL || stack[fd][0] == '\0')
	{
		//if (!ret && *line && !stack[fd])
		if (!ret && *line)
		{
			printf("passing here\n");
			*line = NULL;
		}
	printf("val of stack rn %s\n", stack[fd]);
		return (0);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}
/*
int		get_next_line(int fd, char **line)
{
	static char		*line_stack;
	char			*file_content;
	int				ret;

	//---------------
	if (!line || (fd < 0 || fd > MAX_FD) || BUFFER_SIZE < 1 || (read(fd, line_stack, 0) < 0) ||
			!(file_content = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	ft_bzero(file_content, (size_t)BUFFER_SIZE);
	if (line_stack && setup_next_line(&line_stack, line))
	{
		free(file_content);
		return (1);
	}
	//----------------
	ret = gnl_read(fd, file_content, &line_stack, line);
	if (ret == -1)
	{
		free(file_content);
		return (ret);
	}
	//printf("line : \x1b[32m%s\x1b[0m\nline stack :\x1b[31m %s\x1b[0m\nreturn of read : %i\n\n", *line, line_stack, ret);
	free(file_content);
	if (ret != 0 || line_stack == NULL || line_stack[0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = line_stack;
	line_stack = NULL;
//	if (!line_stack || line_stack[0] == '\0')
//		*line = NULL;
	if (ret == 0 && line_stack && !setup_next_line(&line_stack, line))
		*line = ft_strdup(line_stack);
	//printf("last line read : %s\n", *line);
	return (ret == 0 ? 0 : 1);
}*/
