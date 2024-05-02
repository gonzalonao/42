/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:22:16 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/02 15:06:34 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_min(t_stack *stack)
{
	long	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

long	get_max(t_stack *stack)
{
	long	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

void	sort_5(t_stack **a, t_stack **b, char **moves)
{
	int		i;

	i = 0;
	while (i <= stack_size(*a) && stack_size(*b) < 2)
	{
		if ((*a)->value == 0 || (*a)->value == 1)
			pb(a, b, moves);
		else
			ra(a, moves);
		i++;
	}
	sort_3(a, moves);
	if (is_sorted(*b, NULL))
		sb(b, moves);
	pa(a, b, moves);
	pa(a, b, moves);
}

void	sort_3(t_stack **a, char **moves)
{
	long	min;
	long	max;

	if (stack_size(*a) == 2)
	{
		if (!is_sorted(*a, NULL))
			sa(a, moves);
		return ;
	}
	min = get_min(*a);
	max = get_max(*a);
	if ((*a)->value == max)
		ra(a, moves);
	if ((*a)->next->value == min)
		sa(a, moves);
	if ((*a)->next->value == max && (*a)->value == min)
	{
		sa(a, moves);
		ra(a, moves);
	}
	if (((*a)->next)->next->value == min)
		rra(a, moves);
}
