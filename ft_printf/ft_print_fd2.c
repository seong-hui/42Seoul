/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fd2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:52:13 by seonghmo          #+#    #+#             */
/*   Updated: 2023/03/31 15:45:21 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

void	ft_print_addr(unsigned long long a, int *cnt, int len)
{
	char	*hex;
	int		check;

	hex = "0123456789abcdef";
	if (len > 1)
	{
		if (a == 0)
			return ;
		len--;
		ft_print_addr(a / 16, cnt, len);
	}
	check = write(1, &hex[a % 16], 1);
	if (check == -1)
	{
		*cnt = -1;
		return ;
	}
	*cnt += 1;
}

int	ft_longlen(unsigned long long a)
{
	int	i;

	i = 0;
	while (a > 0)
	{
		i++;
		a /= 16;
	}
	return (i);
}

void	ft_print_mem(void *addr, int *cnt)
{
	unsigned long long	a;
	int					len;
	int					check;

	a = (unsigned long long)addr;
	len = ft_longlen(a);
	check = write(1, "0x", 2);
	if (check == -1)
	{
		*cnt = -1;
		return ;
	}
	if (check == -1)
	{
		*cnt = -1;
		return ;
	}
	*cnt += 2;
	ft_print_addr(a, cnt, len);
}

void	ft_putnbr_hex_fd(unsigned int n, int *cnt, char *hex)
{
	int	check;

	if (n > 15)
		ft_putnbr_hex_fd(n / 16, cnt, hex);
	if (*cnt == -1)
		return ;
	check = write(1, &hex[n % 16], 1);
	if (check == -1)
	{
		*cnt = -1;
		return ;
	}
	*cnt += 1;
}
