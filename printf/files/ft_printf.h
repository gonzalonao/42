/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:27:01 by glopez-c          #+#    #+#             */
/*   Updated: 2023/12/15 13:32:05 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printchar_fd(char c, int fd);
int		ft_printstr_fd(char *s, int fd);
int		ft_printnbr_fd(long nb, int fd, int i);
int		ft_printnbr_base_fd(unsigned long nbr, char *base, int fd);
int		ft_printunbr_base_fd(unsigned long nbr, char *base, int fd);
int		ft_printf(char const *s, ...);

#endif
