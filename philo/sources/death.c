/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:02:44 by glopez-c          #+#    #+#             */
/*   Updated: 2024/09/13 12:02:56 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_philos_death(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
	{
		pthread_mutex_lock(&info->philos[i].meal_mutex);
		if (get_time() - info->philos[i].last_meal > info->time_to_die)
		{
			print_action(&info->philos[i], DIED);
			info->stop = true;
			pthread_mutex_unlock(&info->philos[i].meal_mutex);
			return ;
		}
		pthread_mutex_unlock(&info->philos[i].meal_mutex);
		usleep(100);
	}
}

void	check_philos_meals(t_info *info)
{
	int	i;

	i = 0;
	while (info->must_eat != -1 && i < info->num_philo)
	{
		pthread_mutex_lock(&info->philos[i].meal_mutex);
		if (info->philos[i].meals < info->must_eat)
		{
			pthread_mutex_unlock(&info->philos[i++].meal_mutex);
			break ;
		}
		pthread_mutex_unlock(&info->philos[i++].meal_mutex);
	}
	if (i == info->num_philo)
		info->stop = true;
}

void	death(t_info *info)
{
	while (!info->stop)
	{
		check_philos_death(info);
		check_philos_meals(info);
	}
}
