/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:11:06 by seonghmo          #+#    #+#             */
/*   Updated: 2023/04/19 17:19:37 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*allget(int fd, char *backup)
{
	char	buf[BUFFER_SIZE + 1];
	int		i;

	while (!ft_strchr(backup, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			if (backup)
				free(backup);
			return (0);
		}
		if (i == 0)
			break ;
		buf[i] = '\0';
		backup = ft_strjoin(backup, buf);
		if (!backup)
			break ;
	}
	return (backup);
}

char	*parsing(char *backup)
{
	char	*tmp;
	char	*result;
	int		len;
	int		i;

	tmp = ft_strchr(backup, '\n');
	if (!tmp)
	{
		result = ft_strdup(backup);
		if (!result)
			return (0);
		return (result);
	}
	len = ft_strlen(backup) - ft_strlen(tmp);
	result = (char *)malloc(len + 2);
	if (!result)
		return (0);
	i = -1;
	while (++i <= len)
		result[i] = backup[i];
	result[i] = '\0';
	return (result);
}

char	*after_gnl(char *backup)
{
	char	*tmp;
	char	*result;
	int		len;
	int		i;

	tmp = ft_strchr(backup, '\n');
	if (!tmp)
	{
		free(backup);
		return (0);
	}
	tmp++;
	len = ft_strlen(tmp);
	result = (char *)malloc(len + 1);
	if (!result)
	{
		free(backup);
		return (0);
	}
	i = -1;
	while (++i < len)
		result[i] = tmp[i];
	result[i] = '\0';
	free(backup);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = allget(fd, backup);
	if (!backup)
		return (0);
	if (backup[0] == '\0')
		return (ft_free(&backup));
	line = parsing(backup);
	if (!line)
		return (ft_free(&backup));
	backup = after_gnl(backup);
	return (line);
}
