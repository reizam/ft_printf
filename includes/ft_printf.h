/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 03:25:52 by kmazier           #+#    #+#             */
/*   Updated: 2020/12/01 05:57:28 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct	s_flags
{
	int		left_space;
	int		right_space;
	int		left_zero;
	int		amount_show;
	char	type;
}				t_flags;

void	ft_putunbr_fd(unsigned int n, int fd);
int		ft_printf(const char *str, ...);
void	ft_print_arg_pointer(va_list *ap, t_flags *flags, size_t *length);
void	ft_print_arg_string(va_list *ap, t_flags *flags, size_t *length);
void	ft_print_arg_int(va_list *ap, t_flags *flags, size_t *length);
void	ft_print_arg_uint(va_list *ap, t_flags *flags, size_t *length);
void	ft_print_arg_character(va_list *ap, t_flags *flags, size_t *length);
size_t	ft_nblen(int nbr);
size_t	ft_unblen(unsigned int nbr);

#endif