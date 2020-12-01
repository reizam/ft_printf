/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:23:15 by kmazier           #+#    #+#             */
/*   Updated: 2020/11/17 22:58:13 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *next;

	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		(*lst) = NULL;
		(*lst) = next;
	}
	lst = NULL;
}
