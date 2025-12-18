/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 01:31:20 by marvin            #+#    #+#             */
/*   Updated: 2025/10/05 01:31:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_child(int infile, int *fd, char **argv, char **envp)
{
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error_exit("infile");
	if (dup2(infile, STDIN_FILENO) == -1)
		error_exit("dup2 infile");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		error_exit("dup2 pipe write");
	close(fd[0]);
	close(fd[1]);
	execute_cmd(argv[2], envp);
	close(infile);
}

static void	second_child(int outfile, int *fd, char **argv, char **envp)
{
	outfile = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (outfile < 0)
		error_exit("outfile");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		error_exit("dup2 pipe read");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		error_exit("dup2 outfile");
	close(fd[0]);
	close(fd[1]);
	execute_cmd(argv[3], envp);
}

void	pipex(int infile, int outfile, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
		error_exit("pipe");
	pid1 = fork();
	if (pid1 == -1)
		error_exit("fork");
	if (pid1 == 0)
		first_child(infile, fd, argv, envp);
	pid2 = fork();
	if (pid2 == -1)
		error_exit("fork");
	if (pid2 == 0)
		second_child(outfile, fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;

	infile = -1;
	outfile = -1;
	if (argc != 5)
	{
		write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40);
		exit(EXIT_FAILURE);
	}
	pipex(infile, outfile, argv, envp);
	
	close(outfile);
	return (0);
}
