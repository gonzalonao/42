/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:45:57 by glopez-c          #+#    #+#             */
/*   Updated: 2024/09/29 13:22:23 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_only_digits(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	philo_atoi(const char *str)
{
	unsigned long	result;
	int				i;

	i = 0;
	result = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		result = result * 10 + (str[i++] - '0');
	if (result > INT_MAX)
		return (-1);
	return (result);
}

void	print_action(t_philos *philo, t_action action)
{
	if (action != DIED)
		check_philos_death(philo->info);
	pthread_mutex_lock(&philo->info->stop_mutex);
	if (philo->info->stop)
	{
		pthread_mutex_unlock(&philo->info->stop_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->info->stop_mutex);
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
