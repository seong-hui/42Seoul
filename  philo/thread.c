/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:30:46 by seonghmo          #+#    #+#             */
/*   Updated: 2024/01/03 18:56:45 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_action(t_arg *arg, t_philos *philo)
{
	pthread_mutex_lock(&(arg->forks[philo->left_fork]));
	print_philo(arg, philo->id, "has taken a fork");
	if (arg->num_of_philo != 1)
	{
		pthread_mutex_lock(&(arg->forks[philo->right_fork]));
		print_philo(arg, philo->id, "has taken a fork");
		print_philo(arg, philo->id, "is eating");
		pthread_mutex_lock(&(arg->time));
		philo->last_eat_time = get_time();
		pthread_mutex_unlock(&(arg->time));
		philo->eat_cnt += 1;
		pass_time((long long)arg->time_to_eat, arg);
		pthread_mutex_unlock(&(arg->forks[philo->right_fork]));
	}
	pthread_mutex_unlock(&(arg->forks[philo->left_fork]));
	return (0);
}

void	*philos_thread(void *philoData)
{
	t_arg		*arg;
	t_philos	*philo;

	philo = philoData;
	arg = philo->arg;
	if (philo->id % 2)
		usleep(arg->time_to_eat);
	while (!arg->monitor)
	{
		philo_action(arg, philo);
		if (arg->num_of_must_eat == philo->eat_cnt)
		{
			arg->must_eat_cnt++;
			break ;
		}
		print_philo(arg, philo->id, "is sleeping");
		pass_time((long long)arg->time_to_sleep, arg);
		print_philo(arg, philo->id, "is thinking");
	}
	return (0);
}


void	*alone_thread(void *philoData)
{
	t_arg		*arg;
	t_philos	*philo;

	philo = philoData;
	arg = philo->arg;
	pthread_mutex_lock(&(arg->forks[philo->left_fork]));
	print_philo(arg, philo->id, "has taken a fork");
	pthread_mutex_unlock(&(arg->forks[philo->left_fork]));
	return (0);
}
