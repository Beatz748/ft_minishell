/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:41:10 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/06 01:41:56 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_list2	*ft_parse_env(char **env)
{
	t_list2	*my_env;
	int		i;
	char	*p;

	i = 0;
	p = NULL;
	my_env = NULL;
	while (env[i])
	{
		p = ft_strchr(env[i], '=');
		*p = '\0';
		ft_lstadd_back_env(&my_env, ft_lstnew_env(ft_strdup(++p), ft_strdup(env[i])));
		i++;
	}
	return (my_env);
}

char	*ft_get_tiktok(char *str)
{
	t_list2 *tmp;

	tmp = g_env;
	while (tmp && (ft_strcmp(tmp->name, str)))
		tmp = tmp->next;
	if (tmp)
		return (tmp->content);
	return (NULL);
}

char	*ft_get_gome(void)
{
	t_list2	*tmp;
	char	*home;

	home = 0;
	tmp = g_env;
	while (tmp && (ft_strcmp(tmp->name, "HOME")))
		tmp = tmp->next;
	if (tmp)
		home = tmp->content;
	return (home);
}
