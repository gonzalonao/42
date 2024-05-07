/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:10:36 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/07 21:10:56 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
