/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:41:07 by moonseonghu       #+#    #+#             */
/*   Updated: 2024/01/06 22:54:13 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void modify_monitor(t_arg *arg){
	pthread_mutex_lock(&(arg->monitoring));
	arg->monitor = 1;
	pthread_mutex_unlock(&(arg->monitoring));
}

void	check_philos(t_arg *arg, t_philos *philo)
{
	int			i;
	long long	now;

	while (!monitoring_check(arg))
	{
		i = 0;

		pthread_mutex_lock(&(arg->eat_cnt_m));
			int count = arg->must_eat_cnt;
			pthread_mutex_unlock(&(arg->eat_cnt_m));

		
		if ((arg->time_to_eat != 0) && (arg->num_of_philo == count))
		{
			modify_monitor(arg);
		}
		else
		{
			while (i < arg->num_of_philo)
			{
				now = get_time();
				pthread_mutex_lock(&(arg->time));
				if (now - philo[i].last_eat_time > arg->time_to_die)
				{
					pthread_mutex_unlock(&(arg->time));
					print_philo(arg, philo[i].id, "died");
					modify_monitor(arg);
					break ;
				}
				pthread_mutex_unlock(&(arg->time));
				i++;
			}
		}
	}
}

void	alone_philo(t_arg *arg, t_philos *philo)
{
	philo[0].last_eat_time = get_time();
	if (pthread_create(&(philo[0].thread), NULL, alone_thread, &(philo[0])))
	{
		free_thread(arg, philo, 1);
		return ;
	}
	check_philos(arg, philo);
	pthread_join(philo[0].thread, NULL);
	free_thread(arg, philo, 1);
}

int	start_philos(t_arg *arg, t_philos *philos)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < arg->num_of_philo)
	{
		pthread_mutex_lock(&(arg->time));
		philos[i].last_eat_time = get_time();
		pthread_mutex_unlock(&(arg->time));
		if (pthread_create(&(philos[i].thread), NULL, philos_thread, \
		&(philos[i])))
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag)
	{
		free_thread(arg, philos, i);
		return (0);
	}
	check_philos(arg, philos);
	i =0;
	while (i < arg->num_of_philo){
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	free_thread(arg, philos, arg->num_of_philo);
	return (0);
}

void	check_leak(void)
{
	system("leaks philo");
}

int	main(int ac, char **av)
{
	// atexit(check_leak);
	t_arg		arg;
	t_philos	*philos;

	if (ac >= 5 && ac <= 6)
	{
		if (init_arg(ac, av, &arg))
			return (0);
		if (init_philos(&arg, &philos))
			return (0);
		if (arg.num_of_philo == 1)
			alone_philo(&arg, philos);
		else
			start_philos(&arg, philos);
	}
	return (0);
}
