/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 10:24:01 by kmazier           #+#    #+#             */
/*   Updated: 2020/12/01 05:47:28 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_is_char_base(char c, char *base)
{
	unsigned int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_base(char *base)
{
	unsigned int i;
	unsigned int b;

	i = 0;
	b = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
				|| (base[i] >= 9 && base[12] <= 12))
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

int		ft_get_char_base(char c, char *base)
{
	unsigned int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int				n;
	long int		result;
	unsigned int	i;
	unsigned int	blen;

	if (!ft_check_base(base) || (blen = ft_strlen(base)) < 2)
		return (0);
	result = 0;
	i = 0;
	n = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while (str[i] && ft_is_char_base(str[i], base))
	{
		result = result * blen + ft_get_char_base(str[i], base);
		i++;
	}
	return (result * n);
}
