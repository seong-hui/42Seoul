/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonseonghui <moonseonghui@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:44:50 by moonseonghu       #+#    #+#             */
/*   Updated: 2024/01/01 17:37:55 by moonseonghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_arg
{
    int num_of_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat_cnt;
    int num_of_must_eat;
    int monitor;
    long start_time;

    pthread_mutex_t print;
    pthread_mutex_t *forks;
    pthread_mutex_t time;

} t_arg;

typedef struct s_philos
{
    int id;
    int eat_cnt;
    int left_fork;
    int right_fork;
    long last_eat_time;
    pthread_t thread;
    t_arg *arg;

} t_philos;

int ft_atoi(const char *str);

#endif