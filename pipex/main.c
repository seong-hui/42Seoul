/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonseonghui <moonseonghui@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:41:19 by moonseonghu       #+#    #+#             */
/*   Updated: 2023/09/13 20:47:48 by moonseonghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			path = ft_split(envp[i] + 5, ':');
			return (path);
		}
		i++;
	}
	return (0);
}

char	*get_cmd(char **path, char *cmd)
{
	int		i;
	char	*tmp_cmd;
	int		fd;
	char	*tmp;

	i = 0;
	fd = access(cmd, X_OK);
	if (fd != -1)
		return (cmd);
	tmp_cmd = ft_strjoin("/", cmd);
	while (path[i])
	{
		tmp = ft_strjoin(path[i], tmp_cmd);
		fd = access(tmp, X_OK);
		if (fd != -1)
		{
			free(tmp_cmd);
			return (tmp);
		}
		close(fd);
		free(tmp);
		i++;
	}
	free(tmp_cmd);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_arg	arg;

	if (ac != 5)
		exit_error();
	arg.infile = open(av[1], O_RDONLY);
	if (arg.infile == -1)
		perror(NULL);
	arg.outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (arg.outfile == -1)
		perror(NULL);
	arg.path = get_path(envp);
	arg.cmd1_str = ft_split(av[2], ' ');
	arg.cmd2_str = ft_split(av[3], ' ');
	if (arg.cmd1_str == NULL || arg.cmd2_str == NULL)
		perror(NULL);
	arg.cmd1 = get_cmd(arg.path, arg.cmd1_str[0]);
	arg.cmd2 = get_cmd(arg.path, arg.cmd2_str[0]);
	if (arg.cmd1 == NULL || arg.cmd2 == NULL)
		perror(NULL);
	pipex(ac, arg, envp);
}