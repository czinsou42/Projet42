/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:09:14 by czinsou           #+#    #+#             */
/*   Updated: 2025/12/17 17:16:34 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*stash[1024] = {0};
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_and_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = clean_stash(stash[fd]);
	return (line);
}

char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*tmp;

	buffer = malloc(BUFFER_SIZE +1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!find_newline(stash) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buffer);
		free(stash);
		stash = tmp;
		if (!stash)
			return (free(buffer), NULL);
	}
	return (free(buffer), stash);
}

char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_strndup(stash, i);
	return (line);
}

char	*clean_stash(char *stash)
{
	int		i;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strndup(stash + i + 1, ft_strlen(stash + i + 1));
	free(stash);
	return (new_stash);
}

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test1.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("Ligne : %s", line);
	free(line);
	line = get_next_line(fd2);
	printf("Ligne : %s", line);
	free(line);
	line = get_next_line(fd1);
	printf("Ligne : %s", line);
	free(line);
	line = get_next_line(fd2);
	printf("Ligne : %s", line);
	free(line);
	close(fd1);
	close(fd2);
	return (0);
}
