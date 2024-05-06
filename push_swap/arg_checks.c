/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:12:18 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/03 20:13:10 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_intdups(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value > INT_MAX || tmp->value < INT_MIN)
			return (2);
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_check_args(char **argv, int argc)
{
	int	i;
	int	j;

	i = -1;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		while (argv[1][++i])
		{
			while (argv[1][i] == ' ')
				i++;
			j = ft_is_num(argv[1] + i);
			if (!j)
				return (0);
			i += j - 1;
		}
	}
	if (argc > 2)
	{
		while (--argc)
			if (!ft_is_num(argv[argc]))
				return (0);
	}
	return (1);
}
