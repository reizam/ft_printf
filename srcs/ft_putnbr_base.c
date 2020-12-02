/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:17:01 by kmazier           #+#    #+#             */
/*   Updated: 2020/12/02 20:26:51 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_base_nbr(char *base)
{
	unsigned int i;
	unsigned int b;

	i = 0;
	b = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[b])
		{
			if (base[i] == base[b] && i != b)
				return (0);
			b++;
		}
		b = 0;
		i++;
	}
	return (1);
}

void	ft_write(int nb, char *base, unsigned int blen)
{
	if (((unsigned int)nb) > blen - 1)
	{
		ft_write(nb / blen, base, blen);
		nb %= blen;
	}
	ft_putchar_fd(base[nb], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int blen;

	blen = ft_strlen(base);
	if (ft_check_base_nbr(base) && blen > 1)
	{
		if (nbr >= 0)
			ft_write(nbr, base, blen);
		else
		{
			ft_putchar_fd('-', 1);
			ft_write(-nbr, base, blen);
		}
	}
}
