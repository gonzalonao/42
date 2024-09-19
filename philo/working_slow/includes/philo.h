/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:56:09 by glopez-c          #+#    #+#             */
/*   Updated: 2024/09/17 18:56:50 by glopez-c         ###   ########.fr       */
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

typedef struct s_philos	t_philos;

typedef struct s_info
{
	int				num_philo;
	time_t			start;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				must_eat;
	bool			stop;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	t_philos		*philos;
}	t_info;

typedef struct s_philos
{
	pthread_t		thread;
	time_t			last_meal;
	pthread_mutex_t	meal_mutex;
	unsigned int	id;
	int				meals;
	unsigned int	forks[2];
	bool			dead;
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
void	free_info(t_info *info);
void	*philo_life(void *philo);
time_t	get_time(void);
void	print_action(t_philos *philo, t_action action);
void	death(t_info *info);
bool	routine_stop(t_info *info);
void	check_philos_death(t_info *info);
void	check_philos_meals(t_info *info);

#endif