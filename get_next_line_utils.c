/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absafi <absafi@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 21:21:27 by absafi            #+#    #+#             */
/*   Updated: 2026/10/03 22:38:36 by absafi           ###   ########.fr       */
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
		s1[0] = '\0';
	}
	while (s1[s1_size])
		s1_size++;
	result = malloc(s1_size + dest_cpy + 1);
	ft_strlcpy(result, s1, s1_size + 1);
	ft_strlcpy(&result[s1_size], s2, dest_cpy + 1);
	free(s1);
	return (result);
}

static char	*read_line(int fd)
{
	static char	read_buffer[BUFFER_SIZE + 1];
	char		*result;
	char		*ptr;
	int			read_value;

	read_value = 1;
	result = ft_free_and_join(malloc(0), read_buffer, ft_strlen(read_buffer));
	if (find_chr(read_buffer))
	{
		ptr = find_chr(read_buffer);
		ft_strlcpy(read_buffer, ptr + 1, BUFFER_SIZE - (ptr - read_buffer));
		return (result);
	}
	while (read_value)
	{
		read_value = read(fd, read_buffer, BUFFER_SIZE);
		if (read_value == -1)
			return (NULL);
		read_buffer[read_value] = '\0';
		if (read_value > 0)
			result = ft_free_and_join(result, read_buffer, read_value);
		if (find_chr(read_buffer))
		{
			ptr = find_chr(read_buffer);
			ft_strlcpy(read_buffer, ptr + 1, BUFFER_SIZE - (ptr - read_buffer));
			break ;
		}
		else
			read_buffer[0] = '\0';
	}
	return (result);
}
