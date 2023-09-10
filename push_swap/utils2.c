/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:09:45 by seonghmo          #+#    #+#             */
/*   Updated: 2023/07/16 17:11:00 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

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

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	re;

	i = 0;
	sign = 1;
	re = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		re = re * 10 + (str[i] - '0');
		if (sign == 1 && re >= 9223372036854775807)
			return (-1);
		else if (sign == -1 && re > 9223372036854775807)
			return (0);
		i++;
	}
	return ((int)re * sign);
}
