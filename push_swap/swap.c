/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:08:53 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/07 21:09:03 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	if (!(*stack))
		return ;
	if (!(*stack)->next)
		return ;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = (*stack)->prev->next;
	(*stack)->prev->next = *stack;
	(*stack)->prev->prev = NULL;
	(*stack) = (*stack)->prev;
}

void	sa(t_stack **a, char **moves)
{
	swap(a);
	*moves = add_move(*moves, 'e');
}

void	sb(t_stack **b, char **moves)
{
	swap(b);
	*moves = add_move(*moves, 'f');
}
