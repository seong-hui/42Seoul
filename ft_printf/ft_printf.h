/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:15:54 by seonghmo          #+#    #+#             */
/*   Updated: 2023/03/31 15:15:38 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int			ft_printf(const char *format, ...);
void		ft_putnbr_fd(int n, int *cnt);
void		ft_putstr_fd(char *s, int *cnt);
void		ft_putchar_fd(char c, int *cnt);
int			ft_strlen(char *s);
void		ft_putnbr_unsigned_fd(unsigned int n, int *cnt);
void		ft_putnbr_hex_fd(unsigned int n, int *cnt, char *hex);
void		ft_print_mem(void *addr, int *cnt);
int			ft_longlen(unsigned long long a);
void		ft_print_addr(unsigned long long a, int *cnt, int len);
void		print_type(va_list ap, char c, int *cnt);
long long	print_minus(long long nb, int *cnt);
#endif
