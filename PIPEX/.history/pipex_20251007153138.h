/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 01:29:10 by marvin            #+#    #+#             */
/*   Updated: 2025/10/05 01:29:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

void	error_exit(char *msg);
void	free_split(char **arr);
char	**split_cmd(char *cmd);
char	*find_path(char *cmd, char **envp);
void	execute_cmd(char *cmd, char **envp);
void	pipex(int infile, int outfile, char **argv, char **envp);
char	**ft_split(char const *s, char c)

#endif
