/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:48:21 by glopez-c          #+#    #+#             */
/*   Updated: 2024/04/12 21:14:09 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <strings.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft/libft.h"

void	*ft_free(char **ptr);
void	*ft_freearray(char ***ptr);
char	*get_path(char *paths, char **cmd);

#endif
