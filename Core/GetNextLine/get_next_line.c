/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < get_next_line.c >                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_buffer()
{

}

char	*read_line()
{

}

char	*read_file(int fd, char *result)
{
	
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	// read file
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	// read line & update buffer
	line = "";
	return (line);
}
