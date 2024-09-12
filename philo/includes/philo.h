/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:56:09 by glopez-c          #+#    #+#             */
/*   Updated: 2024/09/11 19:32:51 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_info
{
	unsigned int	num_philo;
	time_t			start;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	unsigned int	must_eat;
	bool			stop;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	t_philos		*philos;
}	t_info;

typedef struct s_philos
{
	pthread_t		thread;
	time_t			last_meal;
	pthread_mutex_t	last_meal_mutex;
	unsigned int	id;
	unsigned int	meals;
	unsigned int	forks[2];
	bool 			dead;
	t_info			*info;
}	t_philos;

typedef enum e_action
{
	FORK = 0,
	EAT = 1,
	SLEEP = 2,
	THINK = 3,
	DIED = 4
}	t_action;


int		is_only_digits(char *str);
int		philo_atoi(const char *str);
int		validate_args(int argc, char **argv);
t_info	*init_info(int argc, char **argv);

#endif