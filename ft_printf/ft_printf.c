/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:01:34 by seonghmo          #+#    #+#             */
/*   Updated: 2023/03/31 15:46:28 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_type(va_list ap, char c, int *cnt)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(ap, int), cnt);
	else if (c == 's')
		ft_putstr_fd(va_arg(ap, char *), cnt);
	else if (c == 'p')
		ft_print_mem(va_arg(ap, void *), cnt);
	else if (c == 'd')
		ft_putnbr_fd(va_arg(ap, int), cnt);
	else if (c == 'i')
		ft_putnbr_fd(va_arg(ap, int), cnt);
	else if (c == 'u')
		ft_putnbr_unsigned_fd(va_arg(ap, unsigned int), cnt);
	else if (c == 'x')
		ft_putnbr_hex_fd(va_arg(ap, unsigned int), cnt, "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_hex_fd(va_arg(ap, unsigned int), cnt, "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar_fd('%', cnt);
	else
		*cnt = -1;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			print_type(ap, format[i], &cnt);
		}
		else
			ft_putchar_fd(format[i], &cnt);
		if (cnt == -1)
		{
			va_end(ap);
			return (-1);
		}
		i++;
	}
	va_end(ap);
	return (cnt);
}
