/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:03:41 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/07 20:55:29 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (!moves)
		return ;
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

char	*add_move(char *moves, char move)
{
	char	*new_moves;
	int		i;

	if (!moves)
		return (NULL);
	i = 0;
	while (moves[i])
		i++;
	new_moves = (char *)ft_calloc(i + 2, sizeof(char));
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
		if (moves[i] == 'e')
			write(1, "sa\n", 3);
		if (moves[i] == 'f')
			write(1, "sb\n", 3);
		if (moves[i] == 'g')
			write(1, "rra\n", 4);
		i++;
	}
}
