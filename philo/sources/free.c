/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:40:25 by glopez-c          #+#    #+#             */
/*   Updated: 2024/09/20 16:35:33 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_info(t_info **info, int status)
{
	int	i;

	i = 0;
	if (status == 4)
	{
		while (i < (*info)->num_philo)
			pthread_mutex_destroy(&(*info)->philos[i++].meal_mutex);
		free((*info)->philos);
	}
	i = 0;
	if (status >= 3)
	{
		while ((*info)->forks && i < (*info)->num_philo)
			pthread_mutex_destroy(&(*info)->forks[i++]);
		free((*info)->forks);
	}
	if (status >= 2)
		pthread_mutex_destroy(&(*info)->print_mutex);
	if (status >= 1)
		pthread_mutex_destroy(&(*info)->stop_mutex);
	free(*info);
	*info = NULL;
}
