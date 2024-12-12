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

static char	read_and_stash(int fd, char *stash)
{
	char	*buf;
	char	*temp;
	int	read_bytes;

	read_bytes = 1;
	while (!found_newline(stash) && read_bytes != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		read_bytes = (int)read(fd, buf, BUFFER_SIZE);
		if ((!stash && read_bytes == 0) || read_bytes = -1)
			return (free(buf), NULL);
		buf[read_bytes] = '\0';
		temp = ft_strjoin(stash, buf);
		free(stash);
		stash = temp;
		free(buf);
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	int	i;

	i = 0;
	while (stash[i] && stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash == '\n')
		line = malloc(sizeof(char) * (i + 2));
	else if (stash == '\0')
		line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (free(line), NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		line[i] = stash[i];
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*update_stash(char *stash, char *line)
{
	char	*new_stash;
	int	i;
	int	j;

	i = ft_strlen(line);
	if (!stash[i])
		return (free(stash), stash = NULL, NULL);
	while (stash[i++])
		j++;
	new_stash = malloc(sizeof(char) * (j + 1));
	if (!new_stash)
		return (free(stash), stash = NULL, NULL);
	i = ft_strlen(line);
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	return (free(stash), stash = NULL, new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*temp;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	temp = read_and_stash(fd, &stash);
	if (!temp)
	{
		if (stash)
			free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = temp;
	line = extract_line(stash, line);
	stash = update_stash(stash, line);
	if (line[0] == '\0')
	{
		free(stash);
		stash == NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

int	main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY | O_CREAT);
	while ()
}