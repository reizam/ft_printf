/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 03:25:52 by kmazier           #+#    #+#             */
/*   Updated: 2020/12/03 04:51:29 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_flags
{
	int		spaces;
	int		left_zero;
	int		amount_show;
	int		amount_set;
	int		lzero_set;
	int		spaces_set;
	char	type;
}				t_flags;

size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(long int n, int fd, size_t zero_amount);
void	ft_putunbr_fd(unsigned int n, int fd);
int		ft_printf(const char *, ...);
void	ft_print_arg_pointer(va_list *ap, t_flags *flags, size_t *length);
void	ft_print_arg_string(va_list *ap, t_flags *flags, size_t *length);
void	ft_print_arg_int(va_list *ap, t_flags *flags, size_t *length);
void	ft_print_arg_uint(va_list *ap, t_flags *flags, size_t *length);
void	ft_print_arg_character(va_list *ap, t_flags *flags, size_t *length);
size_t	ft_calc_zero(t_flags *flags, size_t *len, size_t *length, int negative);
void	ft_print_nbflags(t_flags *flags, size_t *len, size_t *length, int negative);
void	ft_print_flags(t_flags *flags, int end, size_t len, size_t *length);
size_t	ft_nblen(long int nbr);
size_t	ft_unblen(unsigned long nbr, int hex);
void	ft_putnbr_base(int nbr, char *base);
void	ft_print_hex(unsigned long n, int maj);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

#endif