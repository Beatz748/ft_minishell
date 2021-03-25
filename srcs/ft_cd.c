/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <tbeedril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:48:00 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/12 21:38:55 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

int		ft_do_cd(char **full)
{
	g_code = chdir(full[1]);
	return (0);
}

int		ft_exec_cd(char **full)
{
	char	dir[MAX_DIR];

	getcwd(dir, MAX_DIR);
	if (!(full[1]))
	{
		g_code = chdir(ft_get_gome());
		return (0);
	}
	else if (ft_strlen2(full) > 2)
		ft_printf("cd: too many arguments\n");
	else if ((g_code = chdir(full[1])) == -1)
		ft_printf("cd: no such file or directory: %s\n", full[1]);
	return (0);
}
