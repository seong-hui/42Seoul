/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonseonghui <moonseonghui@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:15:11 by moonseonghu       #+#    #+#             */
/*   Updated: 2023/09/14 19:34:55 by moonseonghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	arr_free(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free (str[i]);
			i++;
		}
		free (str);
	}
}

void	all_free(t_arg arg)
{
	if (arg.cmd1)
		free(arg.cmd1);
	if (arg.cmd2)
		free(arg.cmd2);
	arr_free(arg.path);
	arr_free(arg.cmd1_str);
	arr_free(arg.cmd2_str);
}
