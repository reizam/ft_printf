/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_punbr_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:17:01 by kmazier           #+#    #+#             */
/*   Updated: 2020/12/01 05:46:58 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_check_base(char *base)
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
	ft_putchar(base[nb]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int blen;

	blen = ft_strlen(base);
	if (ft_check_base(base) && blen > 1)
	{
		if (nbr >= 0)
			ft_write(nbr, base, blen);
		else
		{
			ft_putchar('-');
			ft_write(-nbr, base, blen);
		}
	}
}
