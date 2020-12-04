/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 02:49:48 by kmazier           #+#    #+#             */
/*   Updated: 2020/12/04 02:53:15 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

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

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
