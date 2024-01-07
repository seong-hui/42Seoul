/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:43:37 by seonghmo          #+#    #+#             */
/*   Updated: 2024/01/07 19:30:47 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;
	long			result;

	gettimeofday(&time, NULL);
	result = ((size_t)time.tv_sec * 1000) + ((size_t)time.tv_usec / 1000);
	return (result);
}

void	pass_time(long long wait_time, t_arg *arg)
{
	long long	start;
	long long	now;

	start = get_time();
	while (!monitoring_check(arg))
	{
		now = get_time();
		if (now - start >= wait_time)
			break ;
		usleep(250);
	}
}

void	print_philo(t_arg *arg, int id, char *str)
{
	long long	now;

	now = get_time();
	if (now == -1)
		return ;
	if (!monitoring_check(arg))
		printf("%lld %d %s\n", now - arg->start_time, id, str);
	return ;
}

void	print_philo_died(t_arg *arg, int id, char *str)
{
	long long	now;

	pthread_mutex_lock(&(arg->monitoring));
	now = get_time();
	if (now == -1)
		return ;
	if (!arg->monitor)
		printf("%lld %d %s\n", now - arg->start_time, id, str);
	arg->monitor = 1;
	pthread_mutex_unlock(&(arg->monitoring));
}

int	print_erorr(char *str)
{
	printf("%s\n", str);
	return (0);
}
