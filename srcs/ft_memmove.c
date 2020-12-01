/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:54:51 by kmazier           #+#    #+#             */
/*   Updated: 2020/11/16 23:24:54 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	s1 = (unsigned char*)dest;
	s2 = (unsigned char*)src;
	if (s1 > s2)
		while (0 < n)
		{
			s1[n - 1] = s2[n - 1];
			n--;
		}
	else
		while (i < n)
		{
			s1[i] = s2[i];
			i++;
		}
	return (dest);
}
