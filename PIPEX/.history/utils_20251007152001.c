/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 01:33:58 by marvin            #+#    #+#             */
/*   Updated: 2025/10/05 01:33:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_cmd(char *cmd)
{
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
		error_exit("command split error");
	return (args);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = split_cmd(cmd);
	path = find_path(args[0], envp);
	if (!path)
	{
		free_split(args);
		error_exit("command not found");
	}
	if (execve(path, args, envp) == -1)
	{
		free_split(args);
		free(path);
		error_exit("execve failed");
	}
}

#include "../pipex.h"

static char	**get_paths(char **envp)
{
	int		i;
	char	*path_line;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_line = envp[i] + 5;
			return (ft_split(path_line, ':'));
		}
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*tmp;
	char	*full;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	paths = get_paths(envp);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full, X_OK) == 0)
		{
			free_split(paths);
			return (full);
		}
		free(full);
		i++;
	}
	free_split(paths);
	return (NULL);
}

