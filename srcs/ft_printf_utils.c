/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 04:27:08 by kmazier           #+#    #+#             */
/*   Updated: 2020/12/01 05:00:55 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nblen(int nbr)
{
	size_t len;

	len = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	len++;
	return (len);
}

size_t	ft_unblen(unsigned int nbr)
{
	size_t len;

	len = 0;
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	len++;
	return (len);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		n %= 10;
	}
	ft_putchar_fd(n + 48, fd);
}