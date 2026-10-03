/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absafi <absafi@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 21:16:30 by absafi            #+#    #+#             */
/*   Updated: 2026/09/29 01:41:13 by absafi           ###   ########.fr       */
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

#endif
