/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:05:49 by kmazier           #+#    #+#             */
/*   Updated: 2020/11/19 19:11:36 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int i;
	unsigned int b;

	i = 0;
	if (*little == 0)
		return ((char*)big);
	while (i < len && big[i])
	{
		b = 0;
		while (big[i + b] && big[i + b] == little[b] && i + b < len)
		{
			b++;
			if (little[b] == 0)
				return ((char*)big + i);
		}
		i++;
	}
	return (NULL);
}
