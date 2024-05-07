/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:46:36 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/07 15:06:52 by glopez-c         ###   ########.fr       */
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

// void	ss(t_stack *a, t_stack *b)
// {
// 	swap(a);
// 	swap(b);
// 	write(1, "ss\n", 3);
// }

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dst;
	if (*dst)
		(*dst)->prev = tmp;
	*dst = tmp;
}

void	pa(t_stack **a, t_stack **b, char **moves)
{
	push(a, b);
	*moves = add_move(*moves, 'a');
}

void	pb(t_stack **a, t_stack **b, char **moves)
{
	push(b, a);
	*moves = add_move(*moves, 'b');
}

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
