/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:15:13 by seonghmo          #+#    #+#             */
/*   Updated: 2023/03/24 17:22:32 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*c_src;
	char		*tmp;

	c_src = (const char *)src;
	tmp = (char *)dst;
	if (!c_src && !tmp)
		return (0);
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len > 0)
		{
			tmp[len - 1] = c_src[len - 1];
			len--;
		}
	}
	return (tmp);
}
