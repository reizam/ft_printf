/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 04:27:08 by kmazier           #+#    #+#             */
/*   Updated: 2020/12/03 05:04:34 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nblen(long int nbr)
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

size_t	ft_unblen(unsigned long nbr, int hex)
{
	size_t len;

	len = 0;
	while (nbr > (hex ? 15 : 9))
	{
		nbr /= (hex ? 16 : 10);
		len++;
	}
	len++;
	return (len);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putunbr_fd(n / 10, fd);
		n %= 10;
	}
	ft_putchar_fd(n + 48, fd);
}

void	ft_print_hex(unsigned long n, int maj)
{
	char *hex = maj ? "0123456789ABCDEF" : "0123456789abcdef";
	
	if (n != 0)
	{
		ft_print_hex(n / 16, maj);
		ft_putchar_fd(hex[n % 16] ,1);
	}
}