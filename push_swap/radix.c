/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:41:48 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/07 19:57:43 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_small_stack(t_stack **a, t_stack **b, char **moves)
{
	if (stack_size(*a) <= 3)
	{
		if (!is_sorted(*a, NULL))
			sort_3(a, moves);
		return ;
	}
	if (stack_size(*a) <= 5)
	{
		if (!is_sorted(*a, NULL))
			sort_5(a, b, moves);
	}
}

void	process_stack_a(t_stack **a, t_stack **b, char **moves, long i)
{
	long	j;
	long	size;

	j = 0;
	size = stack_size(*a);
	while (j++ < size)
	{
		if (((*a)->value >> i) & 1)
			ra(a, moves);
		else
			pb(a, b, moves);
	}
}

void	process_stack_b(t_stack **a, t_stack **b, char **moves, long i)
{
	long	size;

	size = stack_size(*b);
	while (size--)
	{
		if (((*b)->value >> i) & 1)
			pa(a, b, moves);
		else
			rb(b, moves);
	}
}

void	handle_large_stack(t_stack **a, t_stack **b, char **moves, long max)
{
	long	i;

	i = 0;
	while (i < max)
	{
		process_stack_a(a, b, moves, i);
		if (++i == max)
		{
			while (*b)
				pa(a, b, moves);
		}
		process_stack_b(a, b, moves, i);
	}
}

void	ft_radix_sort(t_stack **a, t_stack **b, long max)
{
	char	*moves;

	moves = ft_strdup("");
	if (!moves)
		return ;
	if (stack_size(*a) <= 5)
	{
		handle_small_stack(a, b, &moves);
		if (!moves)
			return ;
	}
	else
	{
		handle_large_stack(a, b, &moves, max);
		if (!moves)
			return ;
	}
	simplify_moves(moves);
}
