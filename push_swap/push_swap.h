/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:31:24 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/07 15:06:41 by glopez-c         ###   ########.fr       */
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
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
long	ft_atol(const char *str);
void	ft_free_split(char **split);
void	ft_free_stack(t_stack *stack);
int		ft_isdigit(int c);
int		ft_is_num(char *str);
int		ft_check_intdups(t_stack *stack);
int		ft_check_args(char **argv, int argc);
char	**ft_get_split(char **argv, int argc);
t_stack	*ft_init_stack(char **split);
long	ft_find_max(t_stack *stack);
void	ft_normalize_stack(t_stack *stack);
int		get_index(char move);
void	simplify_moves(char *moves);
int		get_next_move(char *moves, int i);
void	print_moves(char *moves);
char	*add_move(char *moves, char move);

#endif