/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:17:09 by tbeedril          #+#    #+#             */
/*   Updated: 2020/02/12 19:54:01 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
