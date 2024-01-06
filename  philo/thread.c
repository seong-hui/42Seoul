/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonseonghui <moonseonghui@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:30:46 by seonghmo          #+#    #+#             */
/*   Updated: 2024/01/06 02:12:16 by moonseonghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_action(t_arg *arg, t_philos *philo)
{
pthread_mutex_lock(&(arg->forks[philo->left_fork]));
	print_philo(arg, philo->id, "has taken a fork");
	pthread_mutex_lock(&(arg->forks[philo->right_fork]));
	print_philo(arg, philo->id, "has taken a fork");
	print_philo(arg, philo->id, "is eating");
	pthread_mutex_lock(&(arg->time));
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&(arg->time));
	philo->eat_cnt += 1;
	pass_time((long long)arg->time_to_eat, arg);
	
	pthread_mutex_unlock(&(arg->forks[philo->right_fork]));
	pthread_mutex_unlock(&(arg->forks[philo->left_fork]));
	return (0);
}

int	philo_action_left(t_arg *arg, t_philos *philo)
{
pthread_mutex_lock(&(arg->forks[philo->left_fork]));
	print_philo(arg, philo->id, "has taken a fork");
	pthread_mutex_lock(&(arg->forks[philo->right_fork]));
	print_philo(arg, philo->id, "has taken a fork");
	print_philo(arg, philo->id, "is eating");
	pthread_mutex_lock(&(arg->time));
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&(arg->time));
	philo->eat_cnt += 1;
	pass_time((long long)arg->time_to_eat, arg);
	
	pthread_mutex_unlock(&(arg->forks[philo->right_fork]));
	pthread_mutex_unlock(&(arg->forks[philo->left_fork]));
	return (0);
}

int	philo_action_right(t_arg *arg, t_philos *philo)
{
	pthread_mutex_lock(&(arg->forks[philo->right_fork]));
	print_philo(arg, philo->id, "has taken a fork");
	pthread_mutex_lock(&(arg->forks[philo->left_fork]));
	print_philo(arg, philo->id, "has taken a fork");
	print_philo(arg, philo->id, "is eating");
	pthread_mutex_lock(&(arg->time));
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&(arg->time));
	philo->eat_cnt += 1;
	pass_time((long long)arg->time_to_eat, arg);
	
	pthread_mutex_unlock(&(arg->forks[philo->left_fork]));
	pthread_mutex_unlock(&(arg->forks[philo->right_fork]));
	
	return (0);
}


void	*philos_thread(void *philoData)
{
	t_arg		*arg;
	t_philos	*philo;

	philo = philoData;
	arg = philo->arg;
	if (philo->id % 2 == 1)
		usleep(arg->time_to_eat);
	while (!(monitoring_check(arg)))
	{
		// if (arg->num_of_philo == philo->id && philo->eat_cnt == 0)
		// 	usleep(1);
		// philo_action(arg, philo);
		if (philo->id % 2 == 1)
			philo_action_left(arg, philo);
		else
			philo_action_right(arg, philo);
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
