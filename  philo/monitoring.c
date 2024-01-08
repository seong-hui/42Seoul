/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:55:44 by seonghmo          #+#    #+#             */
/*   Updated: 2024/01/08 11:59:12 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	modify_monitor(t_arg *arg)
{
	pthread_mutex_lock(&(arg->monitoring));
	arg->monitor = 1;
	pthread_mutex_unlock(&(arg->monitoring));
}

int	check_ate_all(t_arg *arg)
{
	int	must_eat_count;

	pthread_mutex_lock(&(arg->eat_cnt_m));
	must_eat_count = arg->must_eat_cnt;
	pthread_mutex_unlock(&(arg->eat_cnt_m));
	if (arg->num_of_philo == must_eat_count)
	{
		printf("%s\n", "ate it all!");
		return (1);
	}
	return (0);
}

void	check_philos(t_arg *arg, t_philos *philo)
{
	int			i;
	long long	now;

	while (!monitoring_check(arg))
	{
		i = 0;
		if (check_ate_all(arg))
			modify_monitor(arg);
		else
		{
			while (i < arg->num_of_philo)
			{
				now = get_time();
				pthread_mutex_lock(&(arg->time));
				if (now - philo[i].last_eat_time >= arg->time_to_die)
				{
					pthread_mutex_unlock(&(arg->time));
					print_philo_died(arg, philo[i].id, "died");
					break ;
				}
				pthread_mutex_unlock(&(arg->time));
				i++;
			}
		}
	}
}

int	monitoring_check(t_arg *arg)
{
	pthread_mutex_lock(&(arg->monitoring));
	if (arg->monitor == 1)
	{
		pthread_mutex_unlock(&(arg->monitoring));
		return (1);
	}
	pthread_mutex_unlock(&(arg->monitoring));
	return (0);
}
