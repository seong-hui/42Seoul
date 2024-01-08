/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:41:07 by moonseonghu       #+#    #+#             */
/*   Updated: 2024/01/08 13:17:09 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	alone_philo(t_arg *arg, t_philos *philo)
{
	pthread_mutex_lock(&(arg->time));
	philo[0].last_eat_time = get_time();
	pthread_mutex_unlock(&(arg->time));
	if (pthread_create(&(philo[0].thread), NULL, alone_thread, &(philo[0])))
	{
		free_thread(arg, philo, 0);
		return ;
	}
	check_philos(arg, philo);
	free_thread(arg, philo, arg->num_of_philo);
}

void	start_philos(t_arg *arg, t_philos *philos)
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
		return (free_thread(arg, philos, i));
	check_philos(arg, philos);
	return (free_thread(arg, philos, arg->num_of_philo));
}

int	main(int ac, char **av)
{
	t_arg		arg;
	t_philos	*philos;

	if (ac >= 5 && ac <= 6)
	{
		if (init_arg(ac, av, &arg))
			return (print_erorr("Invaild arguments"));
		if (init_philos(&arg, &philos))
			return (print_erorr("Philo creation error"));
		if (arg.num_of_philo == 1)
			alone_philo(&arg, philos);
		else
			start_philos(&arg, philos);
	}
	else
		print_erorr("Invalid number of arguments");
	return (0);
}
