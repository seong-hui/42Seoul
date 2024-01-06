/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:44:50 by moonseonghu       #+#    #+#             */
/*   Updated: 2024/01/06 22:38:38 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_arg
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_cnt;
	int				num_of_must_eat;
	int				monitor;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	time;
	pthread_mutex_t	monitoring;
	pthread_mutex_t	eat_cnt_m;
	pthread_mutex_t	print;

}	t_arg;

typedef struct s_philos
{
	int			id;
	int			eat_cnt;
	int			left_fork;
	int			right_fork;
	long		last_eat_time;
	pthread_t	thread;
	t_arg		*arg;

}	t_philos;

int     ft_atoi(const char *str);
long    get_time(void);
void    pass_time(long long wait_time, t_arg *arg);
int	print_philo(t_arg *arg, int id, char *str); 
int	init_arg(int ac, char **av, t_arg *arg);
int	init_mutex(t_arg *arg);
int	init_philos(t_arg *arg, t_philos **philos);
void	free_thread(t_arg *arg, t_philos *philos, int len);
void	*philos_thread(void *philoData);
void	*alone_thread(void *philoData);
int monitoring_check(t_arg *arg);
int	philo_action_right(t_arg *arg, t_philos *philo);
int	philo_action_left(t_arg *arg, t_philos *philo);
int	philo_action(t_arg *arg, t_philos *philo);

#endif