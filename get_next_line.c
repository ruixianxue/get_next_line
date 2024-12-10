/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rxue <rxue@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:08:19 by rxue              #+#    #+#             */
/*   Updated: 2024/12/10 19:08:22 by rxue             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
	/*1.get into a loop, read buffer size of characters each time, store it in the string stash
	  2.every time call read and store it in stash, check if there is a newline
	  3.if there is a newline, print stash until the newline, move stash to the first character after newline
	  4.if there is no newline, read next time
	  5.if read() == 0 means the end of the file, return NULL*/
char	*get_next_line(int fd)
{
	static char	*stash;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	read_and_stash(fd, &stash);
	if (stash == NULL)
		return (NULL);
	extract_line(stash, line);
}

void	read_and_stash(int fd, char *stash)
{
	char	*buff;
	int	char_read;

	char_read = 1;
	while (!found_newline(stash) && char_read != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		char_read = (int)read(fd, buff, BUFFER_SIZE);
		if ((!stash && char_read == 0) || char_read = -1)
			return (free(buff), NULL);
		buff[char_read] = '\0';
		stash = ft_strjoin(stash, buff);
	}
}