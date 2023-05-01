/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:40:17 by seonghmo          #+#    #+#             */
/*   Updated: 2023/03/22 19:04:53 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	find_start(char const *s1, char const *set)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (s1[i])
	{
		if (find(s1[i], set))
			start = i + 1;
		else
			break ;
		i++;
	}
	return (start);
}

int	find_end(char const *s1, char const *set)
{
	int	i;
	int	end;

	i = ft_strlen(s1) - 1;
	end = i;
	while (i >= 0)
	{
		if (find(s1[i], set))
			end = i - 1;
		else
			break ;
		i--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		i;
	int		start;
	int		end;

	if (!s1 || !set)
		return (0);
	i = 0;
	start = find_start(s1, set);
	end = find_end(s1, set);
	if (end - start < 0)
		return (ft_strdup(""));
	p = (char *)malloc(end - start + 2);
	if (!p)
		return (0);
	i = 0;
	while (start <= end)
		p[i++] = s1[start++];
	p[i] = '\0';
	return (p);
}
