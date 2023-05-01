/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:04:03 by seonghmo          #+#    #+#             */
/*   Updated: 2023/03/30 16:41:57 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	print_minus(long long nb, int *cnt)
{
	int	check;

	check = write (1, "-", 1);
	if (check == -1)
	{
		*cnt = -1;
		return (-1);
	}
	*cnt += 1;
	nb = nb * (-1);
	return (nb);
}

void	ft_putnbr_fd(int n, int *cnt)
{
	long long	nb;
	char		c;
	int			check;

	nb = (long long)n;
	if (nb < 0)
	{
		nb = print_minus(nb, cnt);
		if (nb < 0)
			return ;
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, cnt);
	if (*cnt == -1)
		return ;
	c = nb % 10 + '0';
	check = write(1, &c, 1);
	if (check == -1)
	{
		*cnt = -1;
		return ;
	}
	*cnt += 1;
}

void	ft_putstr_fd(char *s, int *cnt)
{
	int	check;

	if (s == NULL)
	{
		check = write (1, "(null)", 6);
		if (check == -1)
		{
			*cnt = -1;
			return ;
		}
		*cnt += 6;
	}
	else
	{
		check = write (1, s, ft_strlen(s));
		if (check == -1)
		{
			*cnt = -1;
			return ;
		}
		*cnt += ft_strlen(s);
	}
}

void	ft_putchar_fd(char c, int *cnt)
{
	int	check;

	check = write (1, &c, 1);
	if (check == -1)
	{
		*cnt = -1;
		return ;
	}
	*cnt += 1;
}

void	ft_putnbr_unsigned_fd(unsigned int n, int *cnt)
{
	char	c;
	int		check;

	if (n > 9)
		ft_putnbr_fd(n / 10, cnt);
	if (*cnt == -1)
		return ;
	c = n % 10 + '0';
	check = write(1, &c, 1);
	if (check == -1)
	{
		*cnt = -1;
		return ;
	}
	*cnt += 1;
}
