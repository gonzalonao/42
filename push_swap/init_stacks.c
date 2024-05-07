/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:56:35 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/07 20:08:54 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(long value)
{
	t_stack	*stack;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

t_stack	*ft_init_stack(char **split)
{
	t_stack	*stack;
	t_stack	*first;
	int		i;

	i = 0;
	stack = ft_new_node(ft_atol(split[i]));
	if (!stack)
		return (NULL);
	first = stack;
	while (split[++i])
	{
		stack->next = ft_new_node(ft_atol(split[i]));
		if (!stack->next)
		{
			ft_free_stack(first);
			return (NULL);
		}
		stack->next->prev = stack;
		stack = stack->next;
	}
	return (first);
}

long	ft_find_next_min(t_stack *stack, unsigned int j)
{
	t_stack	*tmp;
	long	min;

	tmp = stack;
	min = LONG_MAX;
	while (tmp)
	{
		if (tmp->value < min && tmp->value >= j)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_normalize_stack(t_stack *stack)
{
	t_stack	*tmp;
	long	i;
	long	j;

	tmp = stack;
	while (tmp)
	{
		tmp->value = tmp->value - INT_MIN;
		tmp = tmp->next;
	}
	i = 0;
	while (1)
	{
		j = ft_find_next_min(stack, i);
		if (j == LONG_MAX)
			break ;
		tmp = stack;
		while (tmp)
		{
			if (tmp->value == j)
				tmp->value = i++;
			tmp = tmp->next;
		}
	}
}

long	ft_find_max(t_stack *stack)
{
	t_stack	*tmp;
	long	max;

	tmp = stack;
	max = LONG_MIN;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}
