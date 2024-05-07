/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:11:08 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/07 21:11:38 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*stack)
		return ;
	if (!(*stack)->next)
		return ;
	last = *stack;
	tmp = (*stack)->next;
	(*stack)->next->prev = NULL;
	while (last->next)
		last = (last)->next;
	last->next = *stack;
	(*stack)->prev = last;
	(*stack)->next = NULL;
	*stack = tmp;
}

void	ra(t_stack **a, char **moves)
{
	rotate(a);
	*moves = add_move(*moves, 'c');
}

void	rb(t_stack **b, char **moves)
{
	rotate(b);
	*moves = add_move(*moves, 'd');
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
