/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:47:49 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/14 20:16:00 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

uint8_t	ft_percent(uint8_t min, uint8_t max, double percent)
{
	uint8_t	colour;

	colour = (min + (uint8_t)(percent * (max - min)));
	return (colour);
}

int	*colour_dup(int colour)
{
	int	*new_colour;

	new_colour = (int *)malloc(sizeof(int) * 1);
	if (!new_colour)
		return (NULL);
	*new_colour = colour;
	return (new_colour);
}

int	get_colour(double percent, int min_colour, int max_colour)
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
	int		colour;

	red = ft_percent((min_colour >> 24) & 0xFF,
			(max_colour >> 24) & 0xFF, percent);
	green = ft_percent((min_colour >> 16) & 0xFF,
			(max_colour >> 16) & 0xFF, percent);
	blue = ft_percent((min_colour >> 8) & 0xFF,
			(max_colour >> 8) & 0xFF, percent);
	colour = ((red << 24) | (green << 16) | (blue << 8) | 0xFF);
	return (colour);
}

char	*ft_capitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

int	ft_colour_atoi_base(const char *str, const char *base)
{
	int	result;
	int	sign;
	int	i;
	int	j;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i])
	{
		j = 0;
		while (base[j] && str[i] != base[j])
			j++;
		if (base[j])
			result = result * ft_strlen(base) + j;
		else
			break ;
		i++;
	}
	result = result << 8 | 0xFF;
	return (result);
}
