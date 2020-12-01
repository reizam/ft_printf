/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 04:27:45 by kmazier           #+#    #+#             */
/*   Updated: 2020/12/01 05:58:03 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_flags(t_flags *flags, int end, size_t len, size_t *length)
{
	int		diff;
	int		type;

	type = end && flags->left_zero > 0 ? 1 : 0; 
	if (end)
		diff = (flags->left_space > 0 ? flags->left_space : flags->left_zero) - len;
	else
		diff = flags->right_space - len;
	if (diff > 0)
		*length += diff;
	while (diff > 0)
	{
		ft_putchar_fd(type ? '0' : ' ', 1);
		diff--;
	}
}

void	ft_print_arg_int(va_list *ap, t_flags *flags, size_t *length)
{
	size_t len;
	double nbr;

	nbr = (double)va_arg(*ap, int);
	*length += (len = ft_nblen(nbr));
	ft_print_flags(flags, 0, len, length);
	ft_putnbr_fd(nbr, 1);
	ft_print_flags(flags, 1, len, length);
}

void	ft_print_arg_uint(va_list *ap, t_flags *flags, size_t *length)
{
	size_t 			len;
	unsigned int nbr;

	nbr = (unsigned int)va_arg(*ap, unsigned int);
	*length += (len = ft_unblen(nbr));
	ft_print_flags(flags, 0, len, length);
	ft_putunbr_fd(nbr, 1);
	ft_print_flags(flags, 1, len, length);
}

void	ft_print_arg_string(va_list *ap, t_flags *flags, size_t *length)
{
	size_t		len;
	const char 	*str;

	str = (const char*)va_arg(*ap, const char*);
	len = ft_strlen(str);
	if (flags->amount_show > 0 && len > (unsigned int)flags->amount_show)
		len = flags->amount_show;
	*length += len;
	ft_print_flags(flags, 0, len, length);
	if (str != NULL)
		write(1, str, len);
	ft_print_flags(flags, 1, len, length);
}

void	ft_print_arg_character(va_list *ap, t_flags *flags, size_t *length)
{
	size_t			len;
	unsigned char 	c;

	c = (unsigned char)va_arg(*ap, int);
	*length += (len = 1);
	ft_print_flags(flags, 0, len, length);
	ft_putchar_fd(c, 1);
	ft_print_flags(flags, 1, len, length);
}

void	ft_print_arg_pointer(va_list *ap, t_flags *flags, size_t *length)
{
	size_t			len;
	unsigned char 	*str;

	str = (unsigned char*)va_arg(*ap, void*);
	*length += (len = 1);
	ft_print_flags(flags, 0, len, length);
	(void)str;
	ft_print_flags(flags, 1, len, length);
}