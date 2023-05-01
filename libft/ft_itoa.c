/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:21:55 by seonghmo          #+#    #+#             */
/*   Updated: 2023/03/22 18:50:26 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cal_str_len(long long n)
{
	int	len;

	len = 1;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

void	put_num(long long n, int len, char *p)
{
	int	i;

	i = 0;
	if (n > 9)
		put_num(n / 10, len - 1, p);
	p[len] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	int			str_len;
	long long	m;
	char		*p;

	m = (long long)n;
	str_len = cal_str_len(m);
	if (m < 0)
	{
		p = (char *)malloc(str_len + 2);
		if (!p)
			return (0);
		p[0] = '-';
		str_len++;
		m = -m;
	}
	else
	{
		p = (char *)malloc(str_len + 1);
		if (!p)
			return (0);
	}
	put_num(m, str_len - 1, p);
	p[str_len] = '\0';
	return (p);
}
