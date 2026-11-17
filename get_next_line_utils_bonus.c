/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line_utils_bonus.c                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: absafi <absafi@student.42amman.com>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/28 21:21:27 by absafi           #+#    #+#              */
/*   Updated: 2026/10/26 14:47:55 by absafi          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memmove(char *dest, char *src, size_t num)
{
	size_t	counter;

	if (!num)
		return (dest);
	counter = 0;
	if (dest < src)
	{
		while (counter < num)
		{
			dest[counter] = src[counter];
			counter++;
		}
		return (dest);
	}
	counter = num - 1;
	while (num > 0)
	{
		dest[counter] = src[counter];
		num--;
		counter--;
	}
	return (dest);
}

char	*ft_strchr(const char *src, int goal_char)
{
	while ((char)*src != (char) goal_char)
	{
		if (*src == '\0')
			return (0);
		src++;
	}
	return ((char *) src);
}

size_t	ft_strlen(const char *string)
{
	size_t	counter;

	counter = 0;
	while (string[counter])
		counter++;
	return (counter);
}

char	*ft_strjoin(char *dest, char *src, size_t size)
{
	char	*result;
	size_t	dest_size;
	size_t	src_size;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (size < src_size)
		src_size = size;
	result = malloc(dest_size + src_size + 1);
	if (!result)
		return (0);
	ft_memmove(result, dest, dest_size + 1);
	ft_memmove(&result[dest_size], src, src_size);
	result[dest_size + src_size] = '\0';
	return (result);
}
