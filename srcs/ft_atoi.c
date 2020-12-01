/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 10:24:01 by kmazier           #+#    #+#             */
/*   Updated: 2020/12/01 23:25:55 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(char *str)
{
	long long int	n;
	long long int	result;
	long int		i;

	result = 0;
	i = 0;
	n = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			result = result * 10 + (long long int)(str[i] - 48);
		else
			break ;
		i++;
	}
	return (result * n);
}
