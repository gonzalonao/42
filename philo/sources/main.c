/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:40:15 by glopez-c          #+#    #+#             */
/*   Updated: 2024/09/13 12:29:47 by glopez-c         ###   ########.fr       */
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

int	start_routine(t_info *info)
{
	if (!start_eating(info))
	{
		printf("Error: Failed to start eating\n");
		return (EXIT_FAILURE);
	}
	death(info);
	stop_eating(info);
	return (EXIT_SUCCESS);
	return (1);
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
	if (start_routine(info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

