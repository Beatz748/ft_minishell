/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:07:37 by kshantel          #+#    #+#             */
/*   Updated: 2020/12/08 07:40:51 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_make_env_copy(char **envp)
{
	char	**cpy;
	size_t	ind;

	ind = 0;
	while (envp[ind] != NULL)
		ind++;
	cpy = (char **)malloc(sizeof(char *) * (ind + 1));
	ind = -1;
	while (envp[++ind] != NULL)
		cpy[ind] = ft_strdup(envp[ind]);
	cpy[ind] = NULL;
	return (cpy);
}

int		main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	g_code = 0;
	g_en = ft_make_env_copy(env);
	g_env = ft_parse_env(env);
	ft_putstr_fd("\033[0;31mpizza-shell ", 1);
	ft_putstr_fd("BY TBEEDRIL && KSHANTEL 🍕 \033[0m \n\n\n", 1);
	ft_minishell();
	return (0);
}
