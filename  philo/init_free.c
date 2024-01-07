/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:25:19 by seonghmo          #+#    #+#             */
/*   Updated: 2024/01/07 20:29:13 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_arg(int ac, char **av, t_arg *arg)
{
	arg->num_of_philo = ft_atoi(av[1]);
	arg->time_to_die = ft_atoi(av[2]);
	arg->time_to_eat = ft_atoi(av[3]);
	arg->time_to_sleep = ft_atoi(av[4]);
	arg->start_time = get_time();
	arg->monitor = 0;
	arg->must_eat_cnt = 0;
	if (arg->num_of_philo <= 0 || arg->time_to_die <= 0 \
	|| arg->time_to_eat <= 0 || arg->time_to_sleep <= 0)
		return (1);
	if (ac == 6)
	{
		arg->num_of_must_eat = ft_atoi(av[5]);
		if (arg->num_of_must_eat <= 0)
			return (1);
	}
	else
		arg->num_of_must_eat = -1;
	return (0);
}

int	init_mutex(t_arg *arg)
{
	int	i;

	if (pthread_mutex_init(&(arg->time), NULL))
		return (1);
	if (pthread_mutex_init(&(arg->monitoring), NULL))
		return (1);
	if (pthread_mutex_init(&(arg->eat_cnt_m), NULL))
		return (1);
	arg->forks = malloc(sizeof(pthread_mutex_t) * arg->num_of_philo);
	if (!(arg->forks))
		return (1);
	i = 0;
	while (i < arg->num_of_philo)
	{
		if (pthread_mutex_init(&(arg->forks[i]), NULL))
			return (1);
		i++;
	}
	return (0);
}

int	init_philos(t_arg *arg, t_philos **philos)
{
	int	i;

	*philos = (t_philos *)malloc(sizeof(t_philos) * arg->num_of_philo);
	if (!(*philos))
		return (1);
	i = 0;
	while (i < arg->num_of_philo)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].eat_cnt = 0;
		(*philos)[i].left_fork = i;
		(*philos)[i].right_fork = (i + 1) % arg->num_of_philo;
		(*philos)[i].last_eat_time = 0;
		(*philos)[i].arg = arg;
		i++;
	}
	if (init_mutex(arg))
		return (1);
	return (0);
}

void	free_thread(t_arg *arg, t_philos *philos, int len)
{
	int	i;

	i = 0;
	while (i < len)
		pthread_join(philos[i++].thread, NULL);
	pthread_mutex_destroy(&(arg->time));
	pthread_mutex_destroy(&(arg->monitoring));
	pthread_mutex_destroy(&(arg->eat_cnt_m));
	i = 0;
	while (i < arg->num_of_philo)
		pthread_mutex_destroy(&(arg->forks[i++]));
	free(arg->forks);
	free(philos);
	return ;
}
