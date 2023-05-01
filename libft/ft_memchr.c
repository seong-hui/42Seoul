/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:49:52 by seonghmo          #+#    #+#             */
/*   Updated: 2023/03/19 21:46:31 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		u_c;
	size_t				i;

	p = (const unsigned char *)s;
	u_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p[i] == u_c)
			return ((void *)(p + i));
		i++;
	}
	return (0);
}
