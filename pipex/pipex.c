/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonseonghui <moonseonghui@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:02:36 by moonseonghu       #+#    #+#             */
/*   Updated: 2023/09/14 19:19:15 by moonseonghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_arg arg, char **envp, int *fds)
{
	if (arg.infile == -1)
	{
		write(2, "No such file or directory\n", 26);
		exit(1);
	}
	close(fds[0]);
	dup2(fds[1], STDOUT_FILENO);
	dup2(arg.infile, STDIN_FILENO);
	close(fds[1]);
	close(arg.infile);
	if (execve(arg.cmd1, arg.cmd1_str, envp) < 0)
	{
		write(2, "command not found\n", 18);
		exit(1);
	}
}

void	last_child(t_arg arg, char **envp, int *fds)
{
	if (arg.outfile == -1)
		exit_error();
	close(fds[1]);
	dup2(fds[0], STDIN_FILENO);
	dup2(arg.outfile, STDOUT_FILENO);
	close(fds[0]);
	close(arg.outfile);
	if (execve(arg.cmd2, arg.cmd2_str, envp) < 0)
	{
		write(2, "command not found\n", 18);
		exit(1);
	}
}

void	close_fife(int *fds, int i)
{
	close(fds[0]);
	close(fds[1]);
	while (i > 0)
	{
		waitpid(-1, 0, 0);
		i--;
	}
}

void	pipex(int ac, t_arg arg, char **envp)
{
	int		fds[2];
	pid_t	pid;
	int		i;

	i = 0;
	pipe(fds);
	if (pipe(fds) < 0)
		exit_error();
	while (i < ac - 3)
	{
		pid = fork();
		if (pid < 0)
			exit_error();
		if (pid == 0)
		{
			if (i == 0)
				first_child(arg, envp, fds);
			else if (i == ac - 4)
				last_child(arg, envp, fds);
		}
		else
			i++;
	}
	close_fife(fds, i);
}
