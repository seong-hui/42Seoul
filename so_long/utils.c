/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonseonghui <moonseonghui@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:11:36 by seonghmo          #+#    #+#             */
/*   Updated: 2023/09/26 16:48:22 by moonseonghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*ft_strdup(char *s1)
{
	char	*p;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	p = (char *)malloc(len + 1);
	if (!p)
		return (0);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1)
		return (0);
	p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
	{
		free(s1);
		return (0);
	}
	i = -1;
	while (s1[++i])
		p[i] = s1[i];
	j = 0;
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	free(s1);
	return (p);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == (char)c)
			return (s + i);
		i++;
	}
	return (0);
}

char	*ft_free(char **s)
{
	free(*s);
	*s = 0;
	return (0);
}
