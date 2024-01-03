/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:41:07 by moonseonghu       #+#    #+#             */
/*   Updated: 2024/01/03 18:56:55 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_philos(t_arg *arg, t_philos *philo)
{
	int			i;
	long long	now;

	while (!arg->monitor)
	{
		i = 0;
		if ((arg->time_to_eat != 0) && (arg->num_of_philo == arg->must_eat_cnt))
			arg->monitor = 1;
		else
		{
			while (i < arg->num_of_philo)
			{
				pthread_mutex_lock(&(arg->time));
				now = get_time();
				if ((now - philo[i].last_eat_time) > arg->time_to_die)
				{
					print_philo(arg, philo[i].id, "died");
					pthread_mutex_unlock(&(arg->time));
					arg->monitor = 1;
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
		philos[i].last_eat_time = get_time();
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
	// 조인을 안하면 프로그램이 먼저 종료되서 쓰레드가 진행되지 않는다.
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
