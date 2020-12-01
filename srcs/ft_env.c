/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:45:55 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/01 16:25:39 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

int		ft_printf_env(void)
{
	t_list2 *tmp;

	tmp = g_env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, "?"))
			printf("%s=%s\n", tmp->name, tmp->content);
		tmp = tmp->next;
	}
	code = 0;
	return (0);
}

char	**ft_path(void)
{
	t_list2	*tm;
	char	**my_pat;

	tm = g_env;
	while (tm->next && ((ft_strcmp(tm->name, "PATH"))))
		tm = tm->next;
	if (!(ft_strcmp(tm->name, "PATH")))
		return (my_pat = ft_split(tm->content, ':'));
	return (NULL);
}

char	*ft_true_path(char **full)
{
	struct stat	buf;
	char		**my_path;
	char		**split;
	char		*full_path;
	char		*tmp;

	if (!(my_path = ft_path()))
		return (NULL);
	split = my_path;
	full_path = NULL;
	while (*my_path)
	{
		if (full_path)
			free(full_path);
		full_path = ft_strjoin(*my_path++, "/");
		tmp = full_path;
		full_path = ft_strjoin(full_path, full[0]);
		free(tmp);
		if (!stat(full_path, &buf) && (buf.st_mode & S_IFMT) == S_IFREG)
		{
			ft_full_free(split);
			return (full_path);
		}
	}
	ft_full_free(split);
	free(full_path);
	return (NULL);
}
