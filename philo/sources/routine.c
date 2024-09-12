/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:48:35 by glopez-c          #+#    #+#             */
/*   Updated: 2024/09/12 19:48:17 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	routine_stop(t_info *info)
{
	pthread_mutex_lock(&info->stop_mutex);
	if (info->stop)
	{
		pthread_mutex_unlock(&info->stop_mutex);
		return (true);
	}
	pthread_mutex_unlock(&info->stop_mutex);
	return (false);
}

void	ft_sleep(t_info *info, time_t time)
{
	time_t	start;

	start = get_time();
	while (get_time() - start < time)
	{
		if (routine_stop(info))
			break ;
		usleep(100);
	}
}


void	eat_sleep(t_philos *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->forks[0]]);
	print_action(philo, FORK);
	pthread_mutex_lock(&philo->info->forks[philo->forks[1]]);
	print_action(philo, FORK);

	print_action(philo, EAT);

	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->last_meal_mutex);

	ft_sleep(philo->info, philo->info->time_to_eat);

	philo->meals++;

	print_action(philo, SLEEP);

	pthread_mutex_unlock(&philo->info->forks[philo->forks[0]]);
	pthread_mutex_unlock(&philo->info->forks[philo->forks[1]]);

	ft_sleep(philo->info, philo->info->time_to_sleep);
}

void	*one_philo(t_philos *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->forks[0]]);
	print_action(philo, FORK);
	ft_sleep(philo->info, philo->info->time_to_die);
	print_action(philo, DIED);
	pthread_mutex_unlock(&philo->info->forks[philo->forks[0]]);
	return (NULL);
}

void	*philo_life(void *data)
{
	t_philos	*philo;

	philo = (t_philos *)data;
	// pthread_mutex_lock(&philo->info->print_mutex);
	// printf("[%ld] Philo %d created\n", get_time() - philo->info->start, philo->id + 1);
	// pthread_mutex_unlock(&philo->info->print_mutex);
	if (philo->info->must_eat == 0)
		return (NULL);
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = philo->info->start;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	if (philo->info->time_to_die == 0)
		return (NULL);
	if (philo->info->num_philo == 1)
		return (one_philo(philo));
	// else if (philo->id % 2)
	// 	think(philo, true);
	while (!routine_stop(philo->info))
	{
		eat_sleep(philo);
		print_action(philo, THINK);
		//think_routine(philo, false);
	}
	return (NULL);
}
