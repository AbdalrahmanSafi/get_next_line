/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: absafi <absafi@student.42amman.com>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/07 17:06:58 by absafi           #+#    #+#              */
/*   Updated: 2026/10/08 02:00:44 by absafi          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*str;
	int		counter = 1;

	fd = open("file.text", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%d) %s", counter, str);
		str = get_next_line(fd);
		counter++;
	}
	close(fd);
	return (0);
}
