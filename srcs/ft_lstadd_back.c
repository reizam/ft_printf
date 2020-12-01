/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:38:21 by kmazier           #+#    #+#             */
/*   Updated: 2020/11/17 22:57:30 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *begin;

	begin = (*alst);
	while ((*alst) && (*alst)->next)
		(*alst) = (*alst)->next;
	if ((*alst))
		(*alst)->next = new;
	else
		(*alst) = new;
	if (begin)
		(*alst) = begin;
}
