/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:49:01 by tbeedril          #+#    #+#             */
/*   Updated: 2020/07/20 14:14:50 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_lltoa_u(long long int n)
{
	size_t		i;
	long long	j;
	char		*str;

	j = n;
	i = (j == 0) ? 1 : 0;
	while (j != 0)
	{
		j = j / 10;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i] = '\0';
	j = n;
	j = (j < 0) ? -j : j;
	while (i-- > 0)
	{
		str[i] = j % 10 + '0';
		j = j / 10;
	}
	return (str);
}

char	*ft_lltoa_uu(unsigned long long n)
{
	size_t			i;
	unsigned int	j;
	char			*str;

	j = n;
	i = (j == 0) ? 1 : 0;
	while (j != 0)
	{
		j = j / 10;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i] = '\0';
	j = n;
	while (i-- > 0)
	{
		str[i] = j % 10 + '0';
		j = j / 10;
	}
	return (str);
}

char	*ft_substr_format(char ***s)
{
	int		len;
	char	*str;
	char	*tmp;

	len = 1;
	tmp = **s;
	while (ft_istype(tmp++) == 0 && *tmp)
		len++;
	str = ft_substr(**s, 0, len);
	**s = tmp;
	return (str);
}

int		ft_abs(int a)
{
	return (a < 0) ? -a : a;
}
