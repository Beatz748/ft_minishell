/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:17:09 by tbeedril          #+#    #+#             */
/*   Updated: 2020/02/12 19:54:01 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	new;
	char	*str;

	if (!(s1))
		return (NULL);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	new = ft_strlen(s1);
	while (ft_strchr(set, s1[new]) && new)
		new--;
	str = ft_substr(s1, 0, new + 1);
	return (str);
}
