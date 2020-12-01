/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 09:47:57 by kmazier           #+#    #+#             */
/*   Updated: 2020/11/16 22:14:10 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t b;
	size_t i;
	size_t j;

	b = 0;
	i = 0;
	while (i < size && dst[i])
		i++;
	if (i == size)
		return (i + (unsigned int)ft_strlen(src));
	j = i;
	while (src[b])
	{
		if (b < size - i - 1)
			dst[j++] = src[b];
		b++;
	}
	dst[j] = 0;
	return (i + b);
}
