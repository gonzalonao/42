/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:27:14 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/06 15:36:43 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int error)
{
	write(2, "Error\n", 6);
	if (error == 1)
		write(1, "Wrong arguments\n", 16);
	if (error == 2)
		write(1, "Error getting split\n", 21);
	if (error == 3)
		write(1, "Error initializing stack\n", 26);
	if (error == 4)
		write(1, "Error: integer overflow\n", 25);
	if (error == 5)
		write(1, "Error: duplicate integers\n", 28);
	exit(1);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**split;
	t_stack	*stack_a;
	t_stack	*stack_b;
	long	max;
	long 	a;

	if (!ft_check_args(argv, argc))
		ft_error(1);
	split = ft_get_split(argv, argc);
	if (!split)
		ft_error(2);
	stack_a = ft_init_stack(split);
	ft_free_split(split);
	if (!stack_a)
		ft_error(3);
	i = ft_check_intdups(stack_a);
	if (i)
	{
		ft_error(i);
		ft_free_stack(stack_a);
	}
	ft_normalize_stack(stack_a);
	a = ft_find_max(stack_a);
	max = 0;
	while (a)
	{
		a >>= 1;
		max++;
	}
	stack_b = NULL;
	ft_radix_sort(&stack_a, &stack_b, max);
	ft_free_stack(stack_a);
	exit(0);
}
