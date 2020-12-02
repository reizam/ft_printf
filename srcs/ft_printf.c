/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 03:21:33 by kmazier           #+#    #+#             */
/*   Updated: 2020/12/02 07:45:09 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_conversions(char c)
{
	return (c == 'd' || c == 'i' || c == 'x' || c == 'X' || c == 's' || c == 'c' || c == 'u' || c == 'p');
}

int		ft_check_flags(t_flags *flags)
{
	return (flags->type != '\0' && flags->left_space != -1 && flags->right_space != -1 && flags->left_zero != -1);
}

int	ft_parse_nb(char *str, size_t *offset)
{
	int		result;
	size_t 	i;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (int)(str[i] - 48);
		else
			break ;
		i++;
	}
	*offset += i;
	return (result);
}
#include <stdio.h>

t_flags	*ft_parse_flags(char *str, va_list *ap, size_t *f_len)
{
	t_flags	*flags;
	size_t	i;

	i = 1;
	if (!(flags = (t_flags*)malloc(sizeof(t_flags))))
		return (NULL);
	flags->type = 0;
	flags->amount_show = 0;
	flags->left_zero = 0;
	flags->left_space = 0;
	flags->right_space = 0;
	while (str[i])
	{
		if (str[i] == '-' && flags->right_space != -1)
			flags->right_space = flags->right_space > 0 ? -1 : ft_parse_nb(str + i + 1, &i);
		else if (str[i] == '*' && flags->left_space != -1)
			flags->left_space = flags->left_space > 0 ? -1 : (int) va_arg(*ap, int);
		else if (str[i] == '0' && flags->left_zero != -1)
			flags->left_zero = flags->left_zero > 0 ? -1 : ft_parse_nb(str + i + 1, &i);
		else if (str[i] == '.' && flags->amount_show != -1)
			flags->amount_show = flags->amount_show > 0 ? -1 : ft_parse_nb(str + i + 1, &i);
		else if (ft_is_conversions(str[i]))
		{
			flags->type = str[i];
			*f_len = i;
			return (flags);
		}
		else
			break ;
		i++;
	}
	free(flags);
	return (NULL);
}

size_t	ft_print_arg(va_list *ap, char *str, size_t *length)
{
	t_flags	*flags;
	size_t	f_len;

	if (!(flags = ft_parse_flags(str, ap, &f_len)) || !ft_check_flags(flags))
		return (0);
	if (flags->type == 'd' || flags->type == 'i')
		ft_print_arg_int(ap, flags, length);
	else if (flags->type == 'x' || flags->type == 'X' || flags->type == 'u')
		ft_print_arg_uint(ap, flags, length);
	else if (flags->type == 's')
		ft_print_arg_string(ap, flags, length);
	else if (flags->type == 'c')
		ft_print_arg_character(ap, flags, length);
	else if (flags->type == 'p')
		ft_print_arg_pointer(ap, flags, length);
	free(flags);
	flags = NULL;
	return (f_len);
}

int		ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	temp;
	size_t	length;
	va_list	ap;
	
	i = -1;
	length = 0;
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (str[i + 1] == '%')
				i++;
			else if ((temp = ft_print_arg(&ap, (char*)str + i, &length)))
			{
				i += temp;
				continue;
			}
		}
		ft_putchar_fd(str[i], 1);
		length++;
	}
	va_end(ap);
	return (length);
}
