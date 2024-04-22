/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:27:14 by glopez-c          #+#    #+#             */
/*   Updated: 2024/04/22 18:09:05 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = ft_strlen(s1);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = 0;
	return (str);
}

long	ft_atol(const char *str)
{
	int		sign;
	long	result;
	size_t	i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - '0');
	result *= sign;
	return (result);
}

static size_t	ft_count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i + 1] == c || !str[i + 1]) && str[i] != c)
			count += 1;
		i++;
	}
	return (count);
}

static void	ft_strwrite(char *dest, char const *src, char c)
{
	size_t	i;

	i = -1;
	while (src[++i] != c && src[i])
		dest[i] = src[i];
	dest[i] = '\0';
}

static int	ft_fillsplit(char **split, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = i;
			while (s[i] != c && s[i])
				i++;
			split[k] = (char *)malloc(sizeof(char) * (i - j + 1));
			if (!split[k])
				return (k);
			ft_strwrite(split[k], s + j, c);
			k++;
		}
	}
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	k;
	int		j;

	k = ft_count_words(s, c);
	split = (char **)malloc((sizeof(char *)) * (k + 1));
	if (!split)
		return (NULL);
	j = ft_fillsplit(split, s, c);
	if (j > -1)
	{
		while (j--)
			free(split[j]);
		free(split);
		return (NULL);
	}
	split[k] = NULL;
	return (split);
}

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

// int	old_check_args(char *argv)
// {
// 	int	i;
// 	int	new;

// 	new = 1;
// 	i = 0;
// 	while (argv[i])
// 	{
// 		if (argv[i] == ' ')
// 		{
// 			i++;
// 			new = 1;
// 		}
// 		if ((argv[i] == '+' || argv[i] == '-' )
// 			&& (!new || !ft_isdigit(argv[i + 1])))
// 			return (0);
// 		if (argv[i] == '+' || argv[i] == '-' || ft_isdigit(argv[i]))
// 			new = 0;
// 		else if (!ft_isdigit(argv[i]))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

int	ft_is_num(char *argv)
{
	int	i;

	i = 0;
	if ((argv[i] == '+' || argv[i] == '-') && ft_isdigit(argv[i + 1]))
		i++;
	while (argv[i])
	{
		if (argv[i] == ' ')
			return (i);
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (i);
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

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		//printf("Freeing %s\n", split[i]);
		free(split[i]);
		i++;
	}
	//printf("Freeing split\n");
	free(split);
}

// int	old_check_dups(char **numbers)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (numbers[i])
// 	{
// 		j = i + 1;
// 		while (numbers[j])
// 		{
// 			if (ft_atoi(numbers[i]) == ft_atoi(numbers[j]))
// 				return (0);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

char	**ft_get_split(char **argv, int argc)
{
	char	**split;
	int		i;

	i = -1;
	if (argc == 2)
		split = ft_split(argv[1], ' ');
	if (argc > 2)
	{
		split = (char **)malloc(sizeof(char *) * (argc - 1));
		if (!split)
			return (NULL);
		while (argc--)
		{
			split[i] = ft_strdup(argv[i + 1]);
			i++;
		}
		split[i] = NULL;
	}
	return (split);
}

void	ft_free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		//printf("Freeing %ld\n", tmp->value);
		free(tmp);
	}
}

t_stack	*ft_new_node(long value)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

t_stack	*ft_init_stack(char **split)
{
	t_stack	*stack;
	t_stack	*first;
	int		i;

	i = 0;
	stack = ft_new_node(ft_atol(split[i]));
	if (!stack)
		return (NULL);
	first = stack;
	while (split[++i])
	{
		stack->next = ft_new_node(ft_atol(split[i]));
		if (!stack->next)
		{
			ft_free_stack(first);
			return (NULL);
		}
		stack->next->prev = stack;
		stack = stack->next;
	}
	return (first);
}

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

long	ft_find_next_min(t_stack *stack, unsigned int j)
{
	t_stack	*tmp;
	long	min;

	tmp = stack;
	min = LONG_MAX;
	while (tmp)
	{
		if (tmp->value < min && tmp->value >= j)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_normalize_stack(t_stack *stack)
{
	t_stack	*tmp;
	long	i;
	long	j;

	tmp = stack;
	while (tmp)
	{
		tmp->value = tmp->value - INT_MIN;
		tmp = tmp->next;
	}
	i = 0;
	while (1)
	{
		j = ft_find_next_min(stack, i);
		if (j == LONG_MAX)
			break ;
		tmp = stack;
		while (tmp)
		{
			if (tmp->value == j)
				tmp->value = i++;
			tmp = tmp->next;
		}
	}
}

long	ft_find_max(t_stack *stack)
{
	t_stack	*tmp;
	long	max;

	tmp = stack;
	max = LONG_MIN;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

void	ft_print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%ld\n", tmp->value);
		tmp = tmp->next;
	}
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;

	tmp = stack_a;
	printf("Stack A:\n");
	while (tmp)
	{
		printf("%ld\n", tmp->value);
		tmp = tmp->next;
	}
	tmp = stack_b;
	printf("Stack B:\n");
	while (tmp)
	{
		printf("%ld\n", tmp->value);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	**split;
	t_stack	*stack_a;
	t_stack	*stack_b;
	long	max;
	long 	a;

	if (!ft_check_args(argv, argc))
	{
		printf("Wrong arguments\n");
		exit(1);
	}
	split = ft_get_split(argv, argc);
	if (!split)
	{
		printf("Error getting split\n");
		exit(1);
	}
	stack_a = ft_init_stack(split);
	ft_free_split(split);
	if (!stack_a)
	{
		printf("Error initializing stack\n");
		exit(1);
	}
	i = ft_check_intdups(stack_a);
	if (i)
	{
		if (i == 2)
			printf("Error: Overflow\n");
		else
			printf("Error: Duplicates\n");
		ft_free_stack(stack_a);
		exit(1);
	}
	ft_normalize_stack(stack_a);
	a = ft_find_max(stack_a);
	max = 0;
	while (a)
	{
		a >>= 1;
		max++;
		printf("Max: %ld\n", max);
	}
	printf("Max: %ld\n", max);
	stack_b = NULL;
	print_stacks(stack_a, stack_b);
	//ra(&stack_a);
	ft_radix_sort(stack_a, stack_b, max);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	printf("OK\n");
}
