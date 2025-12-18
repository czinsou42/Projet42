/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:38:00 by czinsou           #+#    #+#             */
/*   Updated: 2025/12/17 17:13:59 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*stash = {0};
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
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
	if (!stash)
		return (NULL);
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
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("Ligne : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Ligne : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Ligne : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Ligne : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Ligne : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Ligne : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Ligne : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Ligne : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Ligne : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Ligne : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Ligne : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Ligne : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("Ligne : %s", line);
	free(line);
	close(fd);
	return (0);
}
