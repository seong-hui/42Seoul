/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonseonghui <moonseonghui@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:42:43 by moonseonghu       #+#    #+#             */
/*   Updated: 2023/09/13 19:32:34 by moonseonghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_arg
{
	int		infile;
	int		outfile;
	char	**path;
	char	**cmd1_str;
	char	**cmd2_str;
	char	*cmd1;
	char	*cmd2;
}t_arg;

char	**ft_split(char const *s, char c);
int		ft_strncmp(char *s1, const char *s2, int n);
char	*ft_strjoin(char *s1, char *s2);
void	pipex(int ac, t_arg arg, char **envp);
void	exit_error(void);

#endif
