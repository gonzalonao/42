/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:40:15 by glopez-c          #+#    #+#             */
/*   Updated: 2024/09/17 20:14:18 by glopez-c         ###   ########.fr       */
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

int	start_eating(t_info *info)
{
	int	i;

	i = 0;
	info->start = get_time();
	while (i < info->num_philo)
	{
		if (pthread_create(&info->philos[i].thread,
				NULL, &philo_life, &info->philos[i]))
		{
			pthread_mutex_lock(&info->stop_mutex);
			info->stop = true;
			pthread_mutex_unlock(&info->stop_mutex);
			free_info(info);
			write(2, "Error: Fatal error when creating thread\n", 40);
			return (i);
		}
		i++;
	}
	return (0);
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

int	start_routine(t_info *info)
{
	int	i;

	i = start_eating(info);
	if (i)
	{
		while (--i)
			pthread_join(info->philos[i].thread, NULL);
		return (EXIT_FAILURE);
	}
	stop_eating(info);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 5 && argc != 6)
	{
		write(2, "Error: Wrong number of arguments\n", 35);
		return (EXIT_FAILURE);
	}
	if (!validate_args(argc, argv))
	{
		write(2, "Error: Invalid arguments\n", 25);
		return (EXIT_FAILURE);
	}
	info = init_info(argc, argv);
	if (!info)
	{
		write(2, "Error: Fatal error when initializing\n", 37);
		return (EXIT_FAILURE);
	}
	if (start_routine(info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

