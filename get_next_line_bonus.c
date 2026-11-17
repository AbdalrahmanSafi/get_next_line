/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line_bonus.c                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: absafi <absafi@student.42amman.com>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/28 21:17:49 by absafi           #+#    #+#              */
/*   Updated: 2026/10/26 14:47:19 by absafi          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	init(int fd, char **result, char **buffer)
{
	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
		return (0);
	*result = malloc(1);
	if (!*result)
		return (0);
	(*result)[0] = '\0';
	if (!*buffer)
	{
		*buffer = malloc(1);
		if (!*buffer)
		{
			free(*result);
			return (0);
		}
		(*buffer)[0] = '\0';
	}
	return (1);
}

ssize_t	error(char **temp)
{
	free(*temp);
	return (-1);
}

ssize_t	read_line(int fd, char **buffer)
{
	char	*temp;
	char	*temp_buffer;
	ssize_t	bytes_read;

	bytes_read = 1;
	temp = malloc((BUFFER_SIZE + 1));
	temp_buffer = NULL;
	if (!temp)
		return (-1);
	while (!ft_strchr(*buffer, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (error(&temp));
		temp[bytes_read] = '\0';
		temp_buffer = ft_strjoin(*buffer, temp, bytes_read);
		if (!temp_buffer)
			return (error(&temp));
		free(*buffer);
		*buffer = temp_buffer;
	}
	free(temp);
	return (bytes_read);
}

static int	ft_realloc(char **result, char *buf)
{
	char	*temp;
	char	*newline;

	newline = ft_strchr(buf, '\n');
	if (!newline)
	{
		temp = ft_strjoin(*result, buf, ft_strlen(buf));
		if (!temp)
			return (-1);
		free(*result);
		*result = temp;
		return (0);
	}
	temp = ft_strjoin(*result, buf, newline - buf + 1);
	if (!temp)
		return (-1);
	free(*result);
	*result = temp;
	*newline = '\0';
	ft_memmove(buf, newline + 1, ft_strlen(newline + 1) + 1);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*result;
	ssize_t		read_bytes;
	int			realloc_status;

	if (!init(fd, &result, &buffer[fd]))
		return (NULL);
	read_bytes = read_line(fd, &buffer[fd]);
	realloc_status = ft_realloc(&result, buffer[fd]);
	if (read_bytes == -1 || realloc_status == -1 || !*result)
	{
		free(result);
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	if (realloc_status == 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (result);
}
