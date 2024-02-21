/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:03:21 by glopez-c          #+#    #+#             */
/*   Updated: 2024/01/18 22:48:12 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isformat(char c)
{
	size_t	i;
	char	*s;

	s = "cs%diupxX";
	i = -1;
	while (s[++i])
		if (c == s[i])
			return (i + 1);
	return (0);
}

static int	ft_printaux(va_list args, char c)
{
	int		res;

	if (c == 'c')
		res = ft_printchar_fd(va_arg(args, int), 1);
	if (c == '%')
		res = ft_printchar_fd('%', 1);
	if (c == 's')
		res = ft_printstr_fd(va_arg(args, char *), 1);
	if (c == 'd' || c == 'i')
		res = ft_printnbr_fd(va_arg(args, int), 1, 0);
	if (c == 'u')
		res = ft_printnbr_fd(va_arg(args, unsigned int), 1, 0);
	return (res);
}

static int	ft_printhex(va_list args, char c)
{
	int		res;
	long	ptr;

	if (c == 'p')
	{
		ptr = va_arg(args, unsigned long);
		if (!ptr)
		{
			res = ft_printstr_fd("0x0", 1);
			return (res);
		}
		if (ft_printstr_fd("0x", 1) == -1)
			return (-1);
		res = ft_printunbr_base_fd(ptr, "0123456789abcdef", 1) + 2;
	}
	if (c == 'x')
		res = ft_printunbr_base_fd(va_arg(args, unsigned int),
				"0123456789abcdef", 1);
	if (c == 'X')
		res = ft_printunbr_base_fd(va_arg(args, unsigned int),
				"0123456789ABCDEF", 1);
	return (res);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		len;
	int		j;
	int		i;

	if (!s)
		return (0);
	va_start(args, s);
	len = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%' && ft_isformat(s[i + 1]) >= 7)
			j = ft_printhex(args, s[++i]);
		else if (s[i] == '%' && ft_isformat(s[i + 1]) >= 1)
			j = ft_printaux(args, s[++i]);
		else
			j = ft_printchar_fd(s[i], 1);
		if (j == -1)
			return (j);
		len += j;
	}
	va_end(args);
	return (len);
}
/*
int	ft_printchar_fd(char c, int fd)
{
	int	x;

	x = write(fd, &c, 1);
	return (x);
}
static long	ft_valid_base(char *base)
{
	long	x;

	x = -1;
	while (base[++x])
		if (base[x] == '-' || base[x] == '+' || base[x] == base[x + 1])
			return (0);
	if (x <= 1)
		return (0);
	else
		return (x);
}

int	ft_printnbr_base_fd(long nbr, char *base, int fd)
{
	long		size;
	static int	x;

	x = 0;
	size = ft_valid_base(base);
	if (size)
	{
		if (nbr < 0)
		{
			if (write(1, "-", 1) == -1)
				return (-1);
			nbr *= -1;
			x++;
		}
		if (nbr >= size)
			if (ft_printnbr_base_fd(nbr / size, base, fd) == -1)
				return (-1);
		if (ft_printchar_fd(base[nbr % size], fd) == -1)
			return (-1);
		x++;
	}
	return (x);
}

int	ft_printunbr_base_fd(unsigned long nbr, char *base, int fd)
{
	unsigned long	size;
	static int		x;

	x = 0;
	size = ft_valid_base(base);
	if (size)
	{
		if (nbr >= size)
			if (ft_printunbr_base_fd(nbr / size, base, fd) == -1)
				return (-1);
		if (ft_printchar_fd(base[nbr % size], fd) == -1)
			return (-1);
		x++;
	}
	return (x);
}

int	ft_printnbr_fd(long nb, int fd, int j)
{
	static int	x;

	x = j;
	if (nb < 0)
	{
		j = write(fd, "-", 1);
		if (j == -1)
			return (-1);
		nb *= -1;
		x++;
	}
	if (nb > 9)
	{
		if (ft_printnbr_fd(nb / 10, fd, x) == -1)
			return (-1);
		if (ft_printnbr_fd(nb % 10, fd, x) == -1)
			return (-1);
	}
	else
	{
		if (ft_printchar_fd(nb + '0', fd) == -1)
			return (-1);
		x++;
	}
	return (x);
}
int	ft_printstr_fd(char *s, int fd)
{
	size_t		i;
	static int	j;

	if (!s)
	{
		j = write(1, "(null)", 6);
		return (j);
	}
	i = -1;
	while (s[++i])
	{
		j = write(fd, &s[i], 1);
		if (j == -1)
			return (j);
	}
	return ((int)i);
}
*/
/*
#include <stdlib.h>
#include <stdio.h>
int	main(){
	ft_printf("%x%q\n", -1);
	printf("%x%q", -1);

	char c = 'a';
//	char	*ptr = malloc(2 * sizeof(char));
	int		i = -1;
	i = ft_isformat('p');
	printf("%i", i);
	i = ft_printchar_fd('c',1);
	printf("\n%i\n", i);
	fflush(stdout);
	i = ft_printstr_fd("Hola", 1);
	printf("\n%i\n", i);
	fflush(stdout);
//	ptr[0] = 48;
//	ptr[1] = 49;
	i = ft_printf("1\001\002\007\v\010\f\r\n1");
	printf("1\001\002\007\v\010\f\r\n2");
	printf("%i\n", i);
//	i = ft_printnbr_base_fd(200, "0123456789abcdef", 1, 2);
	write(1, "\n", 1);
	ft_printf("%p\na", (void *)-14523);
	int	j = 0;
//	j = printf("Hola%p\n", ptr);
//	ptr++;
	ft_printf("Hola%X\n", 1234);
	printf("Hola%i\n", j);
	
//	int	i;
	unsigned int l;

	l = -2;
	printf("\n%u", l);
	i = ft_printf("\nola%c", c);
	ft_printf("%i", i);
}*/
