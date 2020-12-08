/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:33:33 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/08 06:27:47 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_hand1(char **sub, char **s, int *i)
{
	char	*tmp;

	*sub = ft_itoa(g_code);
	tmp = *s;
	*s = ft_strjoin(*s, *sub);
	free(tmp);
	free(*sub);
	*i += 2;
}

void	ft_hand2(t_dol *hdl, char *str)
{
	hdl->i++;
	hdl->j = 0;
	while (str[hdl->i + hdl->j] != ' ' && str[hdl->i + hdl->j])
		hdl->j++;
	hdl->sub = ft_substr(str, hdl->i, hdl->j);
	hdl->tmp = hdl->s;
	hdl->s = ft_strfjoin(hdl->s, ft_get_tiktok(hdl->sub));
	free(hdl->sub);
	free(hdl->tmp);
	hdl->i += hdl->j;
}

void	ft_hand3(t_dol *hdl, char *str)
{
	hdl->sub = ft_substr(str, hdl->i, hdl->j);
	hdl->tmp = hdl->s;
	hdl->s = ft_strfjoin(hdl->s, hdl->sub);
	free(hdl->sub);
	free(hdl->tmp);
}

char	*ft_some_dol(char *str)
{
	t_dol	*hdl;

	if (!(hdl = malloc(sizeof(t_dol))))
		exit(0);
	hdl->i = 0;
	hdl->s = malloc(1);
	hdl->s[0] = 0;
	while (str[hdl->i])
	{
		if (str[hdl->i + 1] && str[hdl->i] == '$' && str[hdl->i + 1] == '?')
			ft_hand1(&hdl->sub, &hdl->s, &hdl->i);
		if (str[hdl->i] == '$')
			ft_hand2(hdl, str);
		hdl->j = 0;
		while (str[hdl->i + hdl->j] && str[hdl->i + hdl->j] != '$')
			hdl->j++;
		if (hdl->j)
			ft_hand3(hdl, str);
		hdl->i += hdl->j;
	}
	free(hdl);
	return (hdl->s);
}
