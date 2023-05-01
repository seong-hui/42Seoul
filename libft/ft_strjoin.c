/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:23:12 by seonghmo          #+#    #+#             */
/*   Updated: 2023/03/19 20:39:21 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*p;
	int		i;
	int		j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = (char *)malloc(len1 + len2 + 1);
	if (!p)
		return (0);
	i = 0;
	while (i < len1)
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < len1 + len2)
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}
