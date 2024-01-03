/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:43:37 by seonghmo          #+#    #+#             */
/*   Updated: 2024/01/03 18:57:00 by seonghmo         ###   ########.fr       */
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
	while (!(arg->monitor))
	{
		now = get_time();
		if ((now - start) >= wait_time)
			break ;
		usleep(100);
	}
}

int	print_philo(t_arg *arg, int id, char *str)
{
	long long	now;

	now = get_time();
	if (now == -1)
		return (-1);
	if (!(arg->monitor))
	{
		pthread_mutex_lock(&(arg->print));
		printf("%lld %d %s\n", now - arg->start_time, id, str);
		pthread_mutex_unlock(&(arg->print));
	}
	return (0);
}