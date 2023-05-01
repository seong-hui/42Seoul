/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:33:44 by seonghmo          #+#    #+#             */
/*   Updated: 2023/03/24 16:57:56 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	malloc_len;
	void	*p;

	malloc_len = size * count;
	p = malloc(malloc_len);
	if (!p)
		return (0);
	ft_memset(p, 0, malloc_len);
	return (p);
}
