/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:41:48 by glopez-c          #+#    #+#             */
/*   Updated: 2024/04/18 12:44:06 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix_sort(t_stack *a, t_stack *b, long max)
{
	int		i;
	int		j;
	int		digit;

	i = 0;
	max = ft_stack_max(a);
	while (max > 0)
	{
		j = 0;
		while (j < ft_stack_size(a))
		{
			digit = (a->value / i) % 10;
			if (digit == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (b)
			pa(a, b);
		i *= 10;
		max /= 10;
	}
}
