/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonseonghui <moonseonghui@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:02:36 by moonseonghu       #+#    #+#             */
/*   Updated: 2023/09/15 21:06:45 by moonseonghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_arg arg, char **envp, int *pipefd)
{
	if (arg.infile == -1)
	{
		write(2, "No such file or directory\n", 26);
		exit(1);
	}
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	dup2(arg.infile, STDIN_FILENO);
	close(pipefd[1]);
	close(arg.infile);
	if (execve(arg.cmd1, arg.cmd1_str, envp) == -1)
	{
		write(2, "command not found\n", 18);
		exit(1);
	}
}

void	last_child(t_arg arg, char **envp, int *pipefd)
{
	if (arg.outfile == -1)
		exit_error();
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(arg.outfile, STDOUT_FILENO);
	close(pipefd[0]);
	close(arg.outfile);
	if (execve(arg.cmd2, arg.cmd2_str, envp) == -1)
	{
		write(2, "command not found\n", 18);
		exit(1);
	}
}

void	close_fife(int *pipefd, int i)
{
	close(pipefd[0]);
	close(pipefd[1]);
	while (i > 0)
	{
		waitpid(-1, 0, 0);
		i--;
	}
}

void	pipex(int ac, t_arg arg, char **envp)
{
	int		pipefd[2];
	pid_t	pid;
	int		i;

	i = 0;
	pipe(pipefd);
	if (pipe(pipefd) == -1)
		exit_error();
	while (i < ac - 3)
	{
		pid = fork();
		if (pid < 0)
			exit_error();
		if (pid == 0)
		{
			if (i == 0)
				first_child(arg, envp, pipefd);
			else if (i == ac - 4)
				last_child(arg, envp, pipefd);
		}
		else
			i++;
	}
	close_fife(pipefd, i);
}
