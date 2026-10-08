/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line.h                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: absafi <absafi@student.42amman.com>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/28 21:16:30 by absafi           #+#    #+#              */
/*   Updated: 2026/10/08 02:06:27 by absafi          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 42

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
void	*ft_memmove(char *dest, char *src, size_t num);
char	*ft_strchr(const char *src, int goal_char);
char	*ft_strjoin(char *dest, char *src, size_t size);
size_t	ft_strlen(const char *string);
#endif
