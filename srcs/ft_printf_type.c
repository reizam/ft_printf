/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 04:27:45 by kmazier           #+#    #+#             */
/*   Updated: 2020/12/03 09:55:24 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_arg_int(va_list *ap, t_flags *flags, size_t *length)
{
	int			len;
	int			i;
	int			j;
	long int	nbr;
	char		*str;

	i = 0;
	nbr = (long int)va_arg(*ap, int);
	len = ft_strlen((str = ft_itoa(nbr)));
	j = (ft_calc_zero(flags, nbr, len) + (nbr == 0 && flags->amount_set == 1 ? 0 : 1));
	len = len + j;
	ft_print_flags(flags, 0, len, length);
	if (str[0] && str[0] == '-')
	{
		ft_putchar_fd('-', 1);
		i++;
	}
	ft_repeat_character('0', j);
	while (j != -1 && str[i])
		ft_putchar_fd(str[i++], 1);
	ft_print_flags(flags, 1, len, length);
	*length += (size_t)len;
	if (str)
		free(str);
}

void	ft_print_arg_uint(va_list *ap, t_flags *flags, size_t *length)
{
	size_t 			len;
	unsigned int	nbr;
	
	nbr = (unsigned int)va_arg(*ap, unsigned int);
	*length += (len = ft_unblen(nbr, (flags->type == 'x' || flags->type == 'X')));
	ft_print_flags(flags, 0, len, length);
	if ((flags->type == 'x' || flags->type == 'X') && nbr)
		ft_print_hex(nbr, flags->type == 'X');
	else
		ft_putunbr_fd(nbr, 1);
	ft_print_flags(flags, 1, len, length);
}

void	ft_print_arg_string(va_list *ap, t_flags *flags, size_t *length)
{
	size_t		len;
	const char 	*str;

	str = (const char*)va_arg(*ap, const char*);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->amount_set && len > (size_t)flags->amount_show)
		len = (size_t)flags->amount_show > len ? len + 1 : (size_t)flags->amount_show;
	*length += len;
	ft_print_flags(flags, 0, len, length);
	if (str)
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
	unsigned long	n;

	n = (unsigned long)va_arg(*ap, unsigned long);
	*length += (len = (ft_unblen(n, 1) + 2));
	ft_print_flags(flags, 0, len, length);
	ft_putstr_fd("0x", 1);
	if (n)
		ft_print_hex(n, 0);
	else
		ft_putstr_fd("0", 1);
	ft_print_flags(flags, 1, len, length);
}