/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:41:48 by glopez-c          #+#    #+#             */
/*   Updated: 2024/04/24 22:24:06 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned char	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (1);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

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

int	is_rotation(char *move)
{
	if (!ft_strcmp(move, "ra"))
		return (1);
	if (!ft_strcmp(move, "rb"))
		return (2);
	return (0);
}

int	get_next_move(char *moves, int i)
{
	char	current_move;

	current_move = moves[i];
	while (moves[++i])
		if (moves[i] != current_move && moves[i] != ' ')
			return (i);
	return (-1);
}

int	get_index(char move)
{
	if (move == 'a')
		return (0);
	if (move == 'b')
		return (1);
	if (move == 'c')
		return (2);
	if (move == 'd')
		return (4);
	if (move == 'r')
		return (8);
	return (-4);
}

void	simplify_moves(char *moves)
{
	int		i;
	int		next_move;

	i = 0;
	while (moves[i])
	{
		next_move = get_next_move(moves, i);
		if (next_move == -1)
			break ;
		if (get_index(moves[i]) + get_index(moves[next_move]) == 1)
		{
			moves[i] = ' ';
			moves[next_move] = ' ';
		}
		else if (get_index(moves[i]) + get_index(moves[next_move]) == 6)
		{
			moves[i] = 'r';
			moves[next_move] = ' ';
		}
		i++;
	}
	print_moves(moves);
	free(moves);
}

void	ft_radix_sort(t_stack **a, t_stack **b, long max)
{
	long	i;
	long	j;
	long	size;
	char	*moves;

	moves = (char *)malloc(sizeof(char) * 1);
	if (!moves)
		return ;
	moves[0] = '\0';
	i = 0;
	while (i < max)
	{
		j = 0;
		size = stack_size(*a);
		while (j++ < size)
		{
			if (((*a)->value >> i) & 1)
				ra(a, &moves);
			else
				pb(a, b, &moves);
		}
		if (++i == max)
		{
			while (*b)
				pa(a, b, &moves);
		}
		size = stack_size(*b);
		while (size--)
		{
			if (((*b)->value >> i) & 1)
				pa(a, b, &moves);
			else
				rb(b, &moves);
		}
	}
	simplify_moves(moves);
}
