/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:54:37 by kmazier           #+#    #+#             */
/*   Updated: 2020/11/19 19:40:23 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_istrimsep(char c, const char *set)
{
	size_t i;

	if (set == NULL)
		return (0);
	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_gettrimsize(char const *s1, char const *set, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s1 && s1[i] && ft_istrimsep(s1[i], set))
		i++;
	if (i == len)
		return (1);
	j += i;
	i = len;
	while (s1 && i > 0 && ft_istrimsep(s1[i - 1], set))
		i--;
	j += len - i;
	return ((len - j) + 1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = s1 == NULL ? 0 : ft_strlen(s1);
	k = 0;
	if (!(result = (char*)malloc(sizeof(char) * ft_gettrimsize(s1, set, j))))
		return (NULL);
	while (s1 && s1[i] && ft_istrimsep(s1[i], set))
		i++;
	while (s1 && i != j && j > 0 && ft_istrimsep(s1[j - 1], set))
		j--;
	while (s1 && i != j && s1[i] && i < j)
		result[k++] = s1[i++];
	result[k] = 0;
	return (result);
}
