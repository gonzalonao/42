/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:12:18 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/07 20:10:03 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_get_split(char **argv, int argc)
{
	char	**split;
	int		i;

	i = -1;
	if (argc == 2)
		split = ft_split(argv[1], ' ');
	if (argc > 2)
	{
		split = (char **)ft_calloc(argc - 1, sizeof(char *));
		if (!split)
			return (NULL);
		while (argc--)
		{
			split[i] = ft_strdup(argv[i + 1]);
			if (!split[i])
			{
				ft_free_split(split);
				return (NULL);
			}
			i++;
		}
		split[i] = NULL;
	}
	return (split);
}

int	ft_check_intdups(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value > INT_MAX || tmp->value < INT_MIN)
			return (1);
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
	return (i);
}
