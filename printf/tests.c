/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:48:38 by glopez-c          #+#    #+#             */
/*   Updated: 2023/12/12 15:14:19 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_putnbr_fda(long nb, int fd, int i)
{
	static int x;

	x = i;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
		x++;
	}
	if (nb > 9)
	{
		ft_putnbr_fda(nb / 10, fd, x);
		ft_putnbr_fda(nb % 10, fd, x);
	}
	else
	{
		x++;
		ft_putchar_fd(nb + '0', fd);
	}
	return (x);
}

long	ft_valid_base(char *base)
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

int	ft_putnbr_base_fd(long nbr, char *base, int fd, int i)
{
	long	size;
	static int	x;

	x = i;
	size = ft_valid_base(base);
	if (size)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr *= -1;
			x++;
		}
		if (nbr >= size)
			ft_putnbr_base_fd(nbr / size, base, fd, ++x);
		else
			x++;
		ft_putchar_fd(base[nbr % size], fd);
	}
	return (x);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	main(){	
	int i = 0;
	i = ft_putnbr_base_fd(122, "0123456789abcdef", 0, 0);
	printf("%d\n", i);
	fflush(stdout);
	unsigned int	l;
	l = 2148999999;
	i = ft_putnbr_fda(l, 0, 0);
	printf("%d\n", i);
}
/*
int	ft_printf(char const *s, ...)
{
*/
/*
int	main(){
	int	i = 100;
	printf("hol%ñaquetal");
	return 0;
}
*/
/*

void imprimir_argumentos(int num_args, ...) {
    va_list args;
    va_start(args, num_args);

    for (int i = 0; i < num_args; ++i) {
        long valor = va_arg(args, int);
        printf("Argumento %d: %d\n", i + 1, valor);
    }

    va_end(args);
}

int main() {
    imprimir_argumentos(1, 10, 20, 30);
    return 0;
}
*/
/*
#include <stdio.h>
#include <stdarg.h>

void imprimir_argumentos(int num_args, ...) {
    va_list args, args_copia;
    va_start(args, num_args);
    va_copy(args_copia, args);
	int volar = va_arg(args, int);

    // Operaciones con args
    for (int i = 0; i < num_args; ++i) {
        int valor = va_arg(args, int);
        printf("Argumento %d: %d\n", i + 1, valor);
    }
    va_end(args);
    // args_copia se puede seguir utilizando aquí

     for (int i = 0; i < num_args; ++i) {
        int valor2 = va_arg(args_copia, int);
        printf("Argumento %d: %d\n", i + 1, valor2);
    }   va_end(args_copia);
}

int main() {
    imprimir_argumentos(3, 10, 20, 30);
    return 0;
}
*/
