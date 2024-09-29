/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:40:20 by glopez-c          #+#    #+#             */
/*   Updated: 2024/09/29 13:21:39 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_forks(t_philos *philo, t_info *info)
{
	if (philo->id == 0)
	{
		philo->forks[0] = info->num_philo - 1;
		philo->forks[1] = philo->id;
	}
	else if (philo->id % 2 == 0)
	{
		philo->forks[0] = philo->id - 1;
		philo->forks[1] = philo->id;
	}
	else
	{
		philo->forks[0] = philo->id;
		philo->forks[1] = philo->id - 1;
	}
}

int	init_philos(t_info *info)
{
	int			i;

	i = 0;
	info->philos = malloc(sizeof(t_philos) * info->num_philo);
	if (!info->philos)
		return (0);
	while (i < info->num_philo)
	{
		info->philos[i].id = i;
		info->philos[i].meals = 0;
		info->philos[i].last_meal = 0;
		info->philos[i].dead = false;
		info->philos[i].info = info;
		assign_forks(&info->philos[i], info);
		if (pthread_mutex_init(&info->philos[i].meal_mutex, NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&info->philos[i].meal_mutex);
			free(info->philos);
			return (0);
		}
		i++;
	}
	return (1);
}

int	init_forks(t_info *info)
{
	int	i;

	i = 0;
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	if (!info->forks)
		return (0);
	while (i < info->num_philo)
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&info->forks[i]);
			free(info->forks);
			return (0);
		}
		i++;
	}
	return (1);
}

t_info	*init_info(int argc, char **argv)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->num_philo = philo_atoi(argv[1]);
	info->time_to_die = philo_atoi(argv[2]);
	info->time_to_eat = philo_atoi(argv[3]);
	info->time_to_sleep = philo_atoi(argv[4]);
	info->stop = false;
	if (argc == 6)
		info->must_eat = philo_atoi(argv[5]);
	else
		info->must_eat = -1;
	if (pthread_mutex_init(&info->stop_mutex, NULL))
		free_info(&info, 0);
	if (pthread_mutex_init(&info->print_mutex, NULL))
		free_info(&info, 1);
	if (!init_forks(info))
		free_info(&info, 2);
	if (!init_philos(info))
		free_info(&info, 3);
	return (info);
}
