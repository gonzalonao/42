/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:47:49 by glopez-c          #+#    #+#             */
/*   Updated: 2024/05/10 18:22:00 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fdf.h"

uint8_t	ft_percent(uint8_t min, uint8_t max, double percent)
{
	uint8_t	color;

	color = (min + (uint8_t)(percent * (max - min)));
	return (color);
}

int	*get_color(double percent, int min_color, int max_color)
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
	int		*color;

	color = malloc(sizeof(int) * 1);
	red = ft_percent((min_color >> 24) & 0xFF,
			(max_color >> 24) & 0xFF, percent);
	green = ft_percent((min_color >> 16) & 0xFF,
			(max_color >> 16) & 0xFF, percent);
	blue = ft_percent((min_color >> 8) & 0xFF,
			(max_color >> 8) & 0xFF, percent);
	*color = ((red << 24) | (green << 16) | (blue << 8) | 0xFF);
	return (color);
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

int	*ft_atoi_base(const char *str, const char *base)
{
	int	*result;
	int	sign;
	int	i;
	int	j;

	result = (int *)malloc(sizeof(int) * 1);
	*result = 0;
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
			*result = *result * ft_strlen(base) + j;
		else
			break ;
		i++;
	}
	*result *= sign;
	return (result);
}
