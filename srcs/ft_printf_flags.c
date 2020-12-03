/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 07:48:23 by kmazier           #+#    #+#             */
/*   Updated: 2020/12/03 12:38:20 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_calc_zero(t_flags *flags, int nbr, int len)
{
	int		zero;

	zero = 0;		
	if (flags->amount_set && flags->amount_show >= 0)
		zero = flags->amount_show - (len - (nbr < 0));
	else if (flags->lzero_set && flags->spaces >= 0 && !flags->spaces_set)
		zero = flags->left_zero - len;
	if (zero < 0 && nbr != 0)
		zero = 0;
	return (zero);
}

void	ft_print_flags(t_flags *flags, int end, size_t len, size_t *length)
{
	int diff;

	diff = 0;
	if (end && flags->spaces < 0)
		diff = (-flags->spaces) - len;
	else if (!end && flags->spaces > 0)
		diff = flags->spaces - len;
	else if (end && flags->left_zero < 0)
		diff = (-flags->left_zero) - len;
	if (diff > 0)
		*length += diff;
	while (diff > 0)
	{
		ft_putchar_fd(' ', 1);
		diff--;
	}
}