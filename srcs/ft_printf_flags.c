/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 07:48:23 by kmazier           #+#    #+#             */
/*   Updated: 2020/12/03 04:55:59 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_calc_zero(t_flags *flags, size_t *len, size_t *length, int negative)
{
	int 	diff;
	size_t 	zero;

	diff = 0;
	zero = 0;
	diff = flags->lzero_set  == 1 && flags->left_zero > 0 ? flags->left_zero - *len : flags->amount_show - (*len - negative);
	if (diff > 0)
	{
		*length += diff;
		*len += diff;
	}
	while (diff > 0)
	{
		diff--;
		zero++;
	}
	return (zero);
}

void	ft_print_nbflags(t_flags *flags, size_t *len, size_t *length, int negative)
{
	int 	diff;

	diff = 0;
	diff = flags->lzero_set  == 1 && flags->left_zero > 0 ? flags->left_zero - *len : flags->amount_show - (*len - negative);
	if (diff > 0)
	{
		*length += diff;
		*len += diff;
	}
	while (diff > 0)
	{
		ft_putchar_fd('0', 1);
		diff--;
	}
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