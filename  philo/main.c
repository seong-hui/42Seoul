/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonseonghui <moonseonghui@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:41:07 by moonseonghu       #+#    #+#             */
/*   Updated: 2024/01/06 02:10:48 by moonseonghu      ###   ########.fr       */
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

	while (1)
	{
		if (monitoring_check(arg))
			return;
		i = 0;
		if ((arg->time_to_eat != 0) && (arg->num_of_philo == arg->must_eat_cnt))
		{
			modify_monitor(arg);
			// arg->monitor = 1;
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
					// printf("test\n");
					modify_monitor(arg);
					// arg->monitor = 1;
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
