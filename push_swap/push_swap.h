/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:31:24 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/02 14:29:09 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	long			value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void	sa(t_stack **a, char **moves);
void	sb(t_stack **b, char **moves);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack **a, t_stack **b, char **moves);
void	pb(t_stack **a, t_stack **b, char **moves);
void	ra(t_stack **a, char **moves);
void	rb(t_stack **b, char **moves);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, char **moves);
void	rrb(t_stack **b, char **moves);
void	rrr(t_stack **a, t_stack **b);
void	ft_radix_sort(t_stack **a, t_stack **b, long max);
void	print_stacks(t_stack *a, t_stack *b);
char	*add_move(char *moves, char move);
void	print_moves(char *moves);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	sort_3(t_stack **a, char **moves);
void	sort_5(t_stack **a, t_stack **b, char **moves);
int		is_sorted(t_stack *a, t_stack *b);
long	stack_size(t_stack *stack);

#endif