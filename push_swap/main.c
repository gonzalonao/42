/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:27:14 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/07 09:54:47 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	sort_stack(t_stack *stack_a)
{
	long	max;
	long	a;
	t_stack	*stack_b;

	if (is_sorted(stack_a, NULL))
	{
		ft_free_stack(stack_a);
		return (1);
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
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**split;
	t_stack	*stack_a;

	if (!ft_check_args(argv, argc))
		ft_error();
	split = ft_get_split(argv, argc);
	if (!split)
		ft_error();
	stack_a = ft_init_stack(split);
	ft_free_split(split);
	if (!stack_a)
		ft_error();
	i = ft_check_intdups(stack_a);
	if (i)
	{
		ft_error();
		ft_free_stack(stack_a);
	}
	sort_stack(stack_a);
	return (1);
}
