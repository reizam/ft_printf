/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 03:42:11 by kmazier           #+#    #+#             */
/*   Updated: 2020/12/03 05:01:54 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(long int n, int fd, size_t zero_amount)
{
	long long int nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	while (zero_amount > 0)
	{
		ft_putchar_fd('0', 1);
		zero_amount--;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd, 0);
		nbr = nbr % 10;
	}
	ft_putchar_fd(nbr + 48, fd);
}
