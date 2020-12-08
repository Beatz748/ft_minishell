/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:07:37 by kshantel          #+#    #+#             */
/*   Updated: 2020/12/08 16:47:10 by kshantel         ###   ########.fr       */
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

void	ft_minishell(void)
{
	int		i;
	char	*cmd;
	char	dir[MAX_DIR];

	i = 0;
	while (1)
	{
		init_signals(ft_parent_signal);
		write(1, "\033[0;36m Σ>―(〃°ω°〃)♡→ \033[0;35m", 43);
		write(1, getcwd(dir, MAX_DIR), ft_strlen(getcwd(dir, MAX_DIR)));
		write(1, ">\033[0m ", 7);
		if (get_next_line(0, &cmd) == 0)
			exit(g_code);
		init_signals(ft_child_signal);
		ft_parse(cmd);
		free(cmd);
	}
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
