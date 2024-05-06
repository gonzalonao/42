/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:42:29 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/06 14:42:55 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%ld\n", tmp->value);
		tmp = tmp->next;
	}
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;

	tmp = stack_a;
	printf("Stack A:\n");
	while (tmp)
	{
		printf("%ld\n", tmp->value);
		tmp = tmp->next;
	}
	tmp = stack_b;
	printf("Stack B:\n");
	while (tmp)
	{
		printf("%ld\n", tmp->value);
		tmp = tmp->next;
	}
}
