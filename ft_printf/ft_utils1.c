/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:44:25 by tbeedril          #+#    #+#             */
/*   Updated: 2020/07/20 14:10:27 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_istype(char *s)
{
	if (*s == 'c' || *s == 's' || *s == 'p' || *s == 'd' ||
			*s == 'i' || *s == 'u' || *s == 'x' || *s == 'X' ||
			*s == 'n' || *s == 'f' || *s == 'g' || *s == 'e' || *s == '%')
		return (1);
	return (0);
}

int		ft_isflag(char *str)
{
	if (*str == '-' || *str == '+' || *str == ' ' ||
			*str == '#' || *str == '0')
		return (1);
	return (0);
}

int		ft_is_int(char c)
{
	if (c == 'd' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

size_t	ft_wstrlen(wchar_t *s)
{
	int res;

	res = 0;
	while (*s)
	{
		res++;
		s++;
	}
	return (res);
}

char	*ft_itoa_hex(unsigned long long n)
{
	int					i;
	unsigned long long	j;
	char				*str;
	char				*hex;

	j = n;
	i = (j == 0) ? 1 : 0;
	hex = "0123456789abcdef";
	while (j != 0)
	{
		j = j / 16;
		i++;
	}
	if (!(str = (char *)malloc(i + 1)))
		return (NULL);
	str[i] = '\0';
	j = n;
	while (i-- > 0)
	{
		str[i] = hex[j % 16];
		j = j / 16;
	}
	return (str);
}
