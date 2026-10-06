/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line_utils.c                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: absafi <absafi@student.42amman.com>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/28 21:21:27 by absafi           #+#    #+#              */
/*   Updated: 2026/10/05 01:49:40 by absafi          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*find_chr(const char *src)
{
	int	counter;

	counter = 0;
	while (src[counter] != '\n' && counter <= BUFFER_SIZE)
	{
		if (src[counter] == '\0' || counter == BUFFER_SIZE)
			return (NULL);
		counter++;
	}
	return ((char *) & src[counter]);
}

static size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	counter;

	counter = 0;
	if (size > 0)
	{
		while (counter < size - 1 && src[counter])
		{
			dest[counter] = src[counter];
			counter++;
		}
		dest[counter] = '\0';
	}
	return (ft_strlen(src));
}

static char	*ft_free_and_join(char *s1, char const *s2, size_t dest_cpy)
{
	char	*result;
	size_t	s1_size;

	s1_size = 0;
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	while (s1[s1_size])
		s1_size++;
	result = malloc(s1_size + dest_cpy + 1);
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(result, s1, s1_size + 1);
	ft_strlcpy(&result[s1_size], s2, dest_cpy + 1);
	free(s1);
	return (result);
}

static int	prepare_result(char **result, char **read_buf, int read_value)
{
	char	*ptr;

	ptr = find_chr(*read_buf);
	if (ptr)
	{
		*result = ft_free_and_join(*result, *read_buf, ptr - *read_buf + 1);
		if (!*result)
			return (1);
		ft_strlcpy(*read_buf, ptr + 1, read_value - (ptr - *read_buf));
		return (1);
	}
	*result = ft_free_and_join(*result, *read_buf, ft_strlen(*read_buf));
	if (!*result)
		return (1);
	(*read_buf)[0] = '\0';
	return (0);
}

static char	*read_line(int fd)
{
	static char	read_buf[BUFFER_SIZE + 1];
	char		*result;
	int			read_value;

	read_value = 1;
	result = malloc(1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	if (prepare_result(&result, &read_buf, ft_strlen(read_buf)))
		return (result);
	while (read_value)
	{
		read_value = read(fd, read_buf, BUFFER_SIZE);
		if (read_value == -1)
		{
			free(result);
			return (NULL);
		}
		read_buf[read_value] = '\0';
		if (read_value > 0 && prepare_result(&result, &read_buf, read_value))
			return (result);
	}
	return (result);
}
