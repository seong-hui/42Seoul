/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonseonghui <moonseonghui@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:45:17 by seonghmo          #+#    #+#             */
/*   Updated: 2023/12/27 16:24:39 by moonseonghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int ft_atoi(const char *str)
{
	int i;
	int sign;
	unsigned long long re;

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
