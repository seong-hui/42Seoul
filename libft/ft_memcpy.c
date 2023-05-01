/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:34:15 by seonghmo          #+#    #+#             */
/*   Updated: 2023/03/21 15:54:36 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*c_src;
	char		*c_dst;
	size_t		i;

	c_src = (const char *)src;
	c_dst = (char *)dst;
	if (!c_src && !c_dst)
		return (0);
	i = 0;
	while (i < n)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return (dst);
}
