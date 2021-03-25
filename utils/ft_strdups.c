/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdups.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:36:46 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/01 16:48:15 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*str2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str2 = (char *)s;
	while (str2[i] != '\0')
		i++;
	str = (char*)malloc(sizeof(*str2) * (i + 1));
	if (!str)
		return (NULL);
	while (j < i)
	{
		str[j] = str2[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strndup(const char *s, size_t n)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = malloc(sizeof(char) * (n + 1));
	if (res == NULL)
		return (NULL);
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	size_t			j;

	j = s ? ft_strlen(s) : 0;
	if (j < start)
		len = 0;
	if (len > j - start)
		len = j - start;
	i = 0;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	i;
	long	j;
	char	*str;

	j = (long)n;
	i = (j <= 0) ? 1 : 0;
	while (j != 0)
	{
		j = j / 10;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i] = '\0';
	j = (long)n;
	j = (j < 0) ? -j : j;
	while (i-- > 0)
	{
		str[i] = j % 10 + '0';
		j = j / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
