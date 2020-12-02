/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 07:48:23 by kmazier           #+#    #+#             */
/*   Updated: 2020/12/02 09:44:40 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nb_flags(t_flags *flags, size_t *len, size_t *length)
{
	int diff;
	
	diff = flags->amount_show > 0 ? flags->amount_show - *len : flags->left_zero - *len;
	if (flags->spaces > 0)
		return ;
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
	if (diff > 0)
		*length += diff;
	while (diff > 0)
	{
		ft_putchar_fd(' ', 1);
		diff--;
	}
}