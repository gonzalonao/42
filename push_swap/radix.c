/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:41:48 by glopez-c          #+#    #+#             */
/*   Updated: 2024/04/24 17:07:26 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a, t_stack *b)
{
	if (b)
		return (0);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

long	stack_size(t_stack *stack)
{
	long	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	ft_radix_sort(t_stack **a, t_stack **b, long max)
{
	long	i;
	long	j;
	long	size;

	i = 0;
	while (i < max)
	{
		j = 0;
		size = stack_size(*a);
		if (is_sorted(*a, *b))
			return ;
		while (j++ < size)
		{
			if (((*a)->value >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		if (++i == max)
		{
			while (*b)
				pa(a, b);
		}
		size = stack_size(*b);
		while (size--)
		{
			if (((*b)->value >> i) & 1)
				pa(a, b);
			else
				rb(b);
		}
	}
}
