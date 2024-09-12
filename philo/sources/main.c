/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:40:15 by glopez-c          #+#    #+#             */
/*   Updated: 2024/09/12 20:18:07 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_args(int argc, char **argv)
{
	int	i;
	int	x;

	i = 1;
	while (i < argc)
	{
		if (!is_only_digits(argv[i]))
			return (0);
		x = philo_atoi(argv[i]);
		if (x < 0)
			return (0);
		if (i == 1 && x < 1)
			return (0);
		i++;
	}
	return (1);
}

void	free_info(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	free(info->forks);
	free(info->philos);
	pthread_mutex_destroy(&info->print_mutex);
	free(info);
}

int	start_eating(t_info *info)
{
	int	i;

	i = 0;
	info->start = get_time();
	while (i < info->num_philo)
	{
		if (pthread_create(&info->philos[i].thread, NULL, &philo_life, &info->philos[i]))
		{
			free_info(info);
			printf("Error: Failed to create thread\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	stop_eating(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		pthread_join(info->philos[i].thread, NULL);
		i++;
	}
	free_info(info);
}

void	death(t_info *info)
{
	int	i;

	while (!info->stop)
	{
		i = -1;
		while (++i < info->num_philo)
		{
			pthread_mutex_lock(&info->philos[i].last_meal_mutex);
			if (get_time() - info->philos[i].last_meal > info->time_to_die)
			{
				print_action(&info->philos[i], DIED);
				info->stop = true;
				pthread_mutex_unlock(&info->philos[i].last_meal_mutex);
				return ;
			}
			pthread_mutex_unlock(&info->philos[i].last_meal_mutex);
			usleep(100);
		}
		i = 0;
		while (info->must_eat != -1 && i < info->num_philo)
			if (info->philos[i++].meals < info->must_eat)
				break ;
		if (i == info->num_philo)
			info->stop = true;
	}
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 5 && argc != 6)
	{
		printf("%s\n", "Cambiar error");
		return (EXIT_FAILURE);
	}
	if (!validate_args(argc, argv))
	{
		printf("Error: Invalid arguments\n");
		return (EXIT_FAILURE);
	}
	info = init_info(argc, argv);
	if (!info)
	{
		printf("Error: Failed info init\n");
		return (EXIT_FAILURE);
	}
	if (!start_eating(info))
	{
		printf("Error: Failed to start eating\n");
		return (EXIT_FAILURE);
	}
	death(info);
	stop_eating(info);
	return (EXIT_SUCCESS);
}

