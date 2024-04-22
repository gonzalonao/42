/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:41:48 by glopez-c          #+#    #+#             */
/*   Updated: 2024/04/22 18:20:26 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_radix_sort(t_stack *a, t_stack *b, long max)
{
	long	i;
	long	j;
	long	size;

	i = 0;
	while (i < max)
	{
		j = 0;
		size = stack_size(a);
		while (j < size)
		{
			if ((a->value >> i) & 1)
				ra(&a);
			else
				pb(&a, &b);
			print_stacks(a, b);
			j++;
		}
		while (b)
		{
			pa(&a, &b);
			print_stacks(a, b);
		}
		i++;
	}
}
