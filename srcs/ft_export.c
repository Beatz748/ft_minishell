/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:40:01 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/08 06:03:53 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

int		ft_export(char **full)
{
	char	*p_e;
	t_list2	*tmp;
	int		i;

	i = 1;
	while (full[i])
	{
		p_e = NULL;
		tmp = g_env;
		if (!(p_e = ft_strchr(full[i], '=')))
			p_e = "";
		else
		{
			*p_e = '\0';
			p_e++;
		}
		while (tmp && ft_strcmp(tmp->name, full[i]) != 0)
			tmp = tmp->next;
		if (!tmp)
			ft_ladd_prev(&g_env, ft_lenv(ft_strdup(p_e), ft_strdup(full[i])));
		else
			tmp->content = ft_strdup(p_e);
		i++;
	}
	return (g_code = 0);
}
