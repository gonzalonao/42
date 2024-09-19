/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:40:25 by glopez-c          #+#    #+#             */
/*   Updated: 2024/09/19 16:44:39 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_info(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
		pthread_mutex_destroy(&info->philos[i++].meal_mutex);
	free(info->philos);
	i = 0;
	while (info->forks && i < info->num_philo)
		pthread_mutex_destroy(&info->forks[i++]);
	free(info->forks);
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->stop_mutex);
	free(info);
}
