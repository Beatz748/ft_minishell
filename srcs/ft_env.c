/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:45:55 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/08 07:34:52 by kshantel         ###   ########.fr       */
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
			printf("%s=%s\n", tmp->name, tmp->cntent);
		tmp = tmp->next;
	}
	g_code = 0;
	return (0);
}

void	ft_clean_path(char **full_path, char *full, char *path)
{
	char	*tmp;

	*full_path = ft_strjoin(path, "/");
	tmp = *full_path;
	*full_path = ft_strjoin(*full_path, full);
	free(tmp);
}

char	**ft_path(void)
{
	t_list2	*tm;
	char	**my_pat;

	tm = g_env;
	while (tm->next && ((ft_strcmp(tm->name, "PATH"))))
		tm = tm->next;
	if (!(ft_strcmp(tm->name, "PATH")))
		return (my_pat = ft_split(tm->cntent, ':'));
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
		ft_clean_path(&full_path, full[0], *my_path++);
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
