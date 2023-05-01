/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:33:10 by seonghmo          #+#    #+#             */
/*   Updated: 2023/03/20 15:02:24 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && len >= needle_len)
	{
		if (ft_strncmp(haystack + i, needle, needle_len) == 0)
			return ((char *)(haystack + i));
		i++;
		len--;
	}
	return (0);
}
