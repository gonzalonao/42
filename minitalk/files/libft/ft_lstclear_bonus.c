/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:15:20 by glopez-c          #+#    #+#             */
/*   Updated: 2023/12/05 13:24:48 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	if (lst)
	{
		while (*lst)
		{
			first = *lst;
			new = (*lst)->next;
			if (first->content && del)
				del((first)->content);
			free(first);
			*lst = new;
		}
		*lst = NULL;
	}
}
