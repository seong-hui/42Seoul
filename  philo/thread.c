/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:30:46 by seonghmo          #+#    #+#             */
/*   Updated: 2024/01/06 22:55:54 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_action(t_arg *arg, t_philos *philo)
{
	pthread_mutex_lock(&(arg->forks[philo->right_fork]));
	print_philo(arg, philo->id, "has taken a fork");
	pthread_mutex_lock(&(arg->forks[philo->left_fork]));
	print_philo(arg, philo->id, "has taken a fork");
	print_philo(arg, philo->id, "is eating");
	pthread_mutex_lock(&(arg->time));
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&(arg->time));
	pass_time((long long)arg->time_to_eat, arg);
	philo->eat_cnt += 1;
	pthread_mutex_unlock(&(arg->forks[philo->left_fork]));
	pthread_mutex_unlock(&(arg->forks[philo->right_fork]));

	// 	pthread_mutex_lock(&(arg->forks[philo->left_fork]));
	// print_philo(arg, philo->id, "has taken a fork");
	// pthread_mutex_lock(&(arg->forks[philo->right_fork]));
	// print_philo(arg, philo->id, "has taken a fork");
	// print_philo(arg, philo->id, "is eating");
	// pthread_mutex_lock(&(arg->time));
	// philo->last_eat_time = get_time();
	// pthread_mutex_unlock(&(arg->time));
	// philo->eat_cnt += 1;
	// pass_time((long long)arg->time_to_eat, arg);
	// pthread_mutex_unlock(&(arg->forks[philo->right_fork]));
	// pthread_mutex_unlock(&(arg->forks[philo->left_fork]));
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
	pass_time((long long)arg->time_to_eat, arg);
	philo->eat_cnt += 1;
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
		usleep(arg->time_to_eat * 100);
	while (!(monitoring_check(arg)))
	{
		// if (philo->id % 2 == 0)
		// 	philo_action_right(arg, philo);
		// else
		// 	philo_action_left(arg, philo);
		philo_action(arg, philo);
		
		if (arg->num_of_must_eat == philo->eat_cnt)
		{
			pthread_mutex_lock(&(arg->eat_cnt_m));
			arg->must_eat_cnt++;
			pthread_mutex_unlock(&(arg->eat_cnt_m));
			break ;
		}
		print_philo(arg, philo->id, "is sleeping");
		pass_time((long long)arg->time_to_sleep, arg);
		// if (arg->num_of_philo % 2 == 1)
		// 	usleep(1000);
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
