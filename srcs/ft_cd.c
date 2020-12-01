/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:48:00 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/01 15:14:42 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

int		ft_do_cd(char **full)
{
	code = chdir(full[1]);
	return (0);
}

int		ft_exec_cd(char **full)
{
	char	dir[MAX_DIR];

	getcwd(dir, MAX_DIR);
	if (!(full[1]))
	{
		code = chdir(ft_get_gome());
		return (0);
	}
	else if (ft_strlen2(full) > 2)
		printf("cd: too many arguments\n");
	else if (chdir(full[1]) == -1)
		printf("cd: no such file or directory: %s\n", full[1]);
	code = 1;
	return (0);
}
