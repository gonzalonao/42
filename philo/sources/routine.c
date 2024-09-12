/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:48:35 by glopez-c          #+#    #+#             */
/*   Updated: 2024/09/11 20:00:08 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philos *philo, t_action action)
{
	pthread_mutex_lock(&philo->info->print_mutex);
	if (action == FORK)
		printf("%ld %d has taken a fork\n",
			get_time() - philo->info->start, philo->id + 1);
	else if (action == EAT)
		printf("%ld %d is eating\n",
			get_time() - philo->info->start, philo->id + 1);
	else if (action == SLEEP)
		printf("%ld %d is sleeping\n",
			get_time() - philo->info->start, philo->id + 1);
	else if (action == THINK)
		printf("%ld %d is thinking\n",
			get_time() - philo->info->start, philo->id + 1);
	else if (action == DIED)
		printf("%ld %d died\n", get_time() - philo->info->start, philo->id + 1);
	pthread_mutex_unlock(&philo->info->print_mutex);
}

void	sleep(t_info *info, time_t time)
{
	time_t	start;

	start = get_time();
	while (get_time() - start < time)
	{
		if (has_simulation_stopped(info))
			break ;
		usleep(100);
	}
}

void	*one_philo(t_philos *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->forks[0]]);
	print_action(philo, FORK);
	sleep(philo->info, philo->info->time_to_die);
	write_status(philo, false, DIED);
	pthread_mutex_unlock(&philo->info->forks[philo->forks[0]]);
	return (NULL);
}

void	*philosopher(void *data)
{
	t_philos	*philo;

	philo = (t_philos *)data;
	if (philo->info->must_eat == 0)
		return (NULL);
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = philo->info->start;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	if (philo->info->time_to_die == 0)
		return (NULL);
	if (philo->info->num_philo == 1)
		return (one_philo(philo));
	else if (philo->id % 2)
		think(philo, true);
	while (has_simulation_stopped(philo->info) == false)
	{
		eat_sleep_routine(philo);
		think_routine(philo, false);
	}
	return (NULL);
}
