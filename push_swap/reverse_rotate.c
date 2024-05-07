/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:13:55 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/07 21:14:12 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;

	if (!*stack)
		return ;
	if (!(*stack)->next)
		return ;
	first = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
	(*stack)->next = first;
	first->prev = *stack;
}

void	rra(t_stack **a, char **moves)
{
	reverse_rotate(a);
	*moves = add_move(*moves, 'g');
}

void	rrb(t_stack **b, char **moves)
{
	reverse_rotate(b);
	*moves = add_move(*moves, 'h');
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
