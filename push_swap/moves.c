/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:46:36 by glopez-c          #+#    #+#             */
/*   Updated: 2024/04/24 21:46:32 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*add_move(char *moves, char move)
{
	char	*new_moves;
	int		i;

	i = 0;
	while (moves[i])
		i++;
	new_moves = (char *)malloc(sizeof(char) * (i + 2));
	if (!new_moves)
		return (NULL);
	i = -1;
	while (moves[++i])
		new_moves[i] = moves[i];
	new_moves[i] = move;
	new_moves[i + 1] = '\0';
	free(moves);
	return (new_moves);
}

void	print_moves(char *moves)
{
	int	i;

	i = 0;
	while (moves[i])
	{
		if (moves[i] == 'a')
			write(1, "pa\n", 3);
		if (moves[i] == 'b')
			write(1, "pb\n", 3);
		if (moves[i] == 'r')
			write(1, "rr\n", 3);
		if (moves[i] == 'c')
			write(1, "ra\n", 3);
		if (moves[i] == 'd')
			write(1, "rb\n", 3);
		i++;
	}
}

void	swap(t_stack *stack)
{
	if (!stack)
		return ;
	if (!stack->next)
		return ;
	stack->prev = stack->next;
	stack->next = stack->prev->next;
	stack->prev->next = stack;
	stack->prev->prev = NULL;
}

void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

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
	//write(1, "pa\n", 3);
	*moves = add_move(*moves, 'a');
}

void	pb(t_stack **a, t_stack **b, char **moves)
{
	push(b, a);
	//write(1, "pb\n", 3);
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
	//write(1, "ra\n", 3);
	*moves = add_move(*moves, 'c');
}

void	rb(t_stack **b, char **moves)
{
	rotate(b);
	//write(1, "rb\n", 3);
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

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
