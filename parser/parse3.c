/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:33:33 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/01 16:52:07 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*ft_some_dol(char *str)
{
	int		i;
	int		j;
	char	*sub;
	char	*s;
	char	*tmp;

	i = 0;
	s = malloc(1);
	s[0] = 0;
	while (str[i])
	{
		if (str[i + 1] && str[i] == '$' && str[i + 1] == '?')
		{
			sub = ft_itoa(code);
			tmp = s;
			s = ft_strjoin(s, sub);
			free(tmp);
			free(sub);
			i += 2;
		}
		if (str[i] == '$')
		{
			i++;
			j = 0;
			while (str[i + j] != ' ' && str[i + j])
				j++;
			sub = ft_substr(str, i, j);
			tmp = s;
			s = ft_strfjoin(s, ft_get_tiktok(sub));
			free(sub);
			free(tmp);
			i += j;
		}
		j = 0;
		while (str[i + j] && str[i + j] != '$')
			j++;
		if (j)
		{
			sub = ft_substr(str, i, j);
			tmp = s;
			s = ft_strfjoin(s, sub);
			free(sub);
			free(tmp);
		}
		i += j;
	}
	return (s);
}
