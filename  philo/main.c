/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonseonghui <moonseonghui@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:41:07 by moonseonghu       #+#    #+#             */
/*   Updated: 2024/01/01 18:52:22 by moonseonghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
long get_time(void);
void ft_pass_time(long long wait_time, t_arg *arg);
int print_philo(t_philos *philo, t_arg *arg, int id, char *str);

int init_arg(int ac, char **av, t_arg *arg)
{
    arg->num_of_philo = ft_atoi(av[1]);
    arg->time_to_die = ft_atoi(av[2]);
    arg->time_to_eat = ft_atoi(av[3]);
    arg->time_to_sleep = ft_atoi(av[4]);
    arg->start_time = get_time();
    arg->monitor = 0;
    if (arg->num_of_philo <= 0 || arg->time_to_die < 0 ||
        arg->time_to_eat < 0 || arg->time_to_sleep < 0)
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

int init_mutex(t_arg *arg)
{
    int i;

    if (pthread_mutex_init(&(arg->print), NULL))
        return (1);
    arg->forks = malloc(sizeof(pthread_mutex_t) * arg->num_of_philo);
    if (!(arg->forks))
        return (1);
    i = 0;
    // 철학자의 현재 상태 표시를 섞이게 나오면 안되므로 출력 권한에 뮤텍스 부여
    while (i < arg->num_of_philo)
    {
        if (pthread_mutex_init(&(arg->forks[i]), NULL))
            return (1);
        i++;
    }
    return (0);
}

int init_philos(t_arg *arg, t_philos **philos)
{
    int i;

    *philos = (t_philos *)malloc(sizeof(t_philos) * arg->num_of_philo);
    if (!(*philos))
        return (1);

    for (i = 0; i < arg->num_of_philo; i++)
    {
        (*philos)[i].id = i + 1; // 포인터가 아닌 배열 구조체에 접근
        (*philos)[i].eat_cnt = 0;
        (*philos)[i].left_fork = i;
        (*philos)[i].right_fork = (i + 1) % arg->num_of_philo;
        (*philos)[i].last_eat_time = get_time();
        (*philos)[i].arg = arg;
    }
    if (init_mutex(arg))
        return (1);
    return (0);
}

int philo_action(t_arg *arg, t_philos *philo)
{
    pthread_mutex_lock(&(arg->forks[philo->left_fork]));
    print_philo(philo, arg, philo->id, "has taken a fork");
    if (arg->num_of_philo != 1)
    {
        pthread_mutex_lock(&(arg->forks[philo->right_fork]));
        print_philo(philo, arg, philo->id, "has taken a fork");
        print_philo(philo, arg, philo->id, "is eating");
        pthread_mutex_lock(&(arg->time));
        philo->last_eat_time = get_time();
        pthread_mutex_unlock(&(arg->time));
        philo->eat_cnt += 1;

        ft_pass_time((long long)arg->time_to_eat, arg);
        pthread_mutex_unlock(&(arg->forks[philo->right_fork]));
    }
    pthread_mutex_unlock(&(arg->forks[philo->left_fork]));
    return (0);
}

long get_time(void)
{
    struct timeval time;
    long result;

    gettimeofday(&time, NULL);
    result = ((size_t)time.tv_sec * 1000) + ((size_t)time.tv_usec / 1000);
    return (result);
}

void ft_pass_time(long long wait_time, t_arg *arg)
{
    long long start;
    long long now;

    start = get_time();
    while (!(arg->monitor))
    {
        now = get_time();
        if ((now - start) >= wait_time)
            break;
        usleep(100);
    }
}

int print_philo(t_philos *philo, t_arg *arg, int id, char *str)
{
    long long now;

    now = get_time();
    if (now == -1)
        return (-1);
    pthread_mutex_lock(&(arg->print));
    if (!(arg->monitor))
    {
        printf("%lld %d %s\n", now - arg->start_time, id, str);
    }
    pthread_mutex_unlock(&(arg->print));
    return (0);
}

void *philos_thread(void *philoData)
{
    t_arg *arg;
    t_philos *philo;

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
            break;
        }
        print_philo(philo, arg, philo->id, "is sleeping");
        ft_pass_time((long long)arg->time_to_sleep, arg);
        print_philo(philo, arg, philo->id, "is thinking");
    }
    return (0);
}

void ft_philos_check_finish(t_arg *arg, t_philos *philo)
{
    int i;
    long long now;

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
                    // printf("%lld %ld %d", now, philo[i].last_eat_time, arg->time_to_die);
                    print_philo(philo, arg, philo[i].id, "died");
                    arg->monitor = 1;
                    break;
                }
                pthread_mutex_unlock(&(arg->time));
                i++;
            }
        }
    }
}

void *alone_thread(void *philoData)
{
    t_arg *arg;
    t_philos *philo;

    philo = philoData;
    arg = philo->arg;

    pthread_mutex_lock(&(arg->forks[philo->left_fork]));
    print_philo(philo, arg, philo->id, "has taken a fork");
    // usleep(arg->time_to_die * 1000);
    pthread_mutex_unlock(&(arg->forks[philo->left_fork]));
    // print_philo(philo, arg, philo->id, "died");
    return (0);
}

void alone_philo(t_arg *arg, t_philos *philo)
{
    if (pthread_create(&(philo[0].thread), NULL, alone_thread, &(philo[0])))
    {
        return;
        // 터질 때 처리
    }
    ft_philos_check_finish(arg, philo);

    pthread_join(philo[0].thread, NULL);
}

int start_philos(t_arg *arg, t_philos *philos)
{
    int i;
    int flag = 0;

    i = 0;

    while (i < arg->num_of_philo)
    {
        philos[i].last_eat_time = get_time();
        // 스레드는 philos_thread 실행
        if (pthread_create(&(philos[i].thread), NULL, philos_thread, &(philos[i])))
        {
            flag = 1;
            break;
        }
        i++;
    }

    if (flag)
    { // 중간에 터졌을 때 처리
      // ft_free_thread(arg, philos);
    }

    ft_philos_check_finish(arg, philos);
    i = 0;
    while (i < arg->num_of_philo)
        pthread_join(philos[i++].thread, NULL);
    // 조인을 안하면 프로그램이 먼저 종료되서 쓰레드가 진행되지 않는다.
    // ft_free_thread(arg, philos);
    return (0);
}

void print_arguments(t_arg *arg, t_philos *philos)
{
    printf("Arguments:\n");
    printf("Number of Philosophers: %d\n", arg->num_of_philo);
    printf("Time to Die: %d\n", arg->time_to_die);
    printf("Time to Eat: %d\n", arg->time_to_eat);
    printf("Time to Sleep: %d\n", arg->time_to_sleep);

    if (arg->num_of_must_eat > 0)
    {
        printf("Number of times each philosopher must eat: %d\n", arg->num_of_must_eat);
    }

    printf("\nPhilosophers:\n");
    for (int i = 0; i < arg->num_of_philo; i++)
    {
        printf("Philosopher %d:\n", philos[i].id);
        printf("  Left Fork: %d\n", philos[i].left_fork);
        printf("  Right Fork: %d\n", philos[i].right_fork);
        printf("  Last Eat Time: %ld\n", philos[i].last_eat_time);
        printf("  Eat Count: %d\n", philos[i].eat_cnt);
        printf("\n");
    }
}

int main(int ac, char **av)
{
    t_arg arg;
    t_philos *philos;

    if (ac >= 5 && ac <= 6)
    {
        if (init_arg(ac, av, &arg))
        {
            printf("error1\n");
            return (0);
        }
        init_philos(&arg, &philos);
        if (!philos)
        {
            printf("error2\n");
            return (0);
        }
        // print_arguments(&arg, philos);
        if (arg.num_of_philo == 1)
            alone_philo(&arg, philos);
        else
            start_philos(&arg, philos);
    }
    else
        return 0;
    return 1;
}
