/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 04:27:45 by kmazier           #+#    #+#             */
/*   Updated: 2020/12/04 06:30:57 by kmazier          ###   ########.fr       */
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
	if (!(str = ft_itoa(nbr)))
		return ;
	len = (int)ft_strlen(str);
	j = (ft_calc_zero(flags, nbr, len));
	len += j > 0 ? j : 0;
	if (j == -1 && nbr == 0 && flags->amount_set && flags->amount_show >= 0)
		len--;
	ft_print_flags(flags, 0, len, length);
	if (str[0] && str[0] == '-')
		ft_putchar_fd('-', (i = 1));
	ft_repeat_character('0', j);
	if (!(j == -1 && nbr == 0 && flags->amount_set && flags->amount_show >= 0))
		while (str[i])
			ft_putchar_fd(str[i++], 1);
	ft_print_flags(flags, 1, len, length);
	*length += len;
	free(str);
}

void	ft_print_arg_uint(va_list *ap, t_flags *flags, size_t *length)
{
	size_t			len;
	unsigned int	nbr;
	int				j;

	nbr = (unsigned int)va_arg(*ap, unsigned int);
	len = ft_unblen(nbr, (flags->type == 'x' || flags->type == 'X'));
	j = (ft_calc_zero_u(flags, nbr, len));
	if (j > 0)
		len += j;
	if (j == -1 && nbr == 0 && flags->amount_set && flags->amount_show >= 0)
		len--;
	ft_print_flags(flags, 0, len, length);
	ft_repeat_character('0', j);
	if (!(j == -1 && nbr == 0 && flags->amount_set && flags->amount_show >= 0))
	{
		if ((flags->type == 'x' || flags->type == 'X') && nbr)
			ft_print_hex(nbr, flags->type == 'X');
		else
			ft_putunbr_fd(nbr, 1);
	}
	ft_print_flags(flags, 1, len, length);
	*length += len;
}

void	ft_print_arg_string(va_list *ap, t_flags *flags, size_t *length)
{
	size_t		len;
	const char	*str;
	int			j;

	j = 0;
	str = (const char*)va_arg(*ap, const char*);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->amount_set && len > (size_t)flags->amount_show)
		len = (size_t)flags->amount_show > len
		? len + 1 : (size_t)flags->amount_show;
	else if (!flags->amount_set && flags->lzero_set && flags->left_zero > 0)
		j = flags->left_zero - len;
	if (j > 0)
	{
		ft_repeat_character('0', j);
		*length += j;
	}
	*length += len;
	ft_print_flags(flags, 0, len + (j > 0 ? j : 0), length);
	if (str)
		write(1, str, len);
	ft_print_flags(flags, 1, len + (j > 0 ? j : 0), length);
}

void	ft_print_arg_character(va_list *ap, t_flags *flags, size_t *length)
{
	size_t			len;
	unsigned char	c;

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
	int				j;

	n = (unsigned long)va_arg(*ap, unsigned long);
	(len = (ft_unblen(n, 1) + 2));
	j = (ft_calc_zero(flags, 1, len - 2));
	if (j > 0)
		len += j;
	ft_print_flags(flags, 0, len, length);
	ft_putstr_fd("0x", 1);
	ft_repeat_character('0', j);
	if (n)
		ft_print_hex(n, 0);
	else
		ft_putchar_fd('0', 1);
	ft_print_flags(flags, 1, len, length);
	*length += len;
}
