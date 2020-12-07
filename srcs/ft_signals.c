/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:54:39 by kshantel          #+#    #+#             */
/*   Updated: 2020/12/07 16:06:20 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_child_signal(int sig)
{
	if (sig == SIGINT)
		ft_putstr_fd("\n", STDOUT_FILENO);
	if (sig == SIGQUIT)
	{
		code = kill(SIGTERM, 0);
	}
}

void	ft_parent_signal(int sig)
{
	char	dir[MAX_DIR];

	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		write(1, "\033[0;36m Σ>―(〃°ω°〃)♡→ \033[0;35m", 43);
		write(1, getcwd(dir, MAX_DIR), ft_strlen(getcwd(dir, MAX_DIR)));
		write(1, ">\033[0m ", 7);
	}
}

void	init_signals(void (*func)(int))
{
	signal(SIGINT, func);
	signal(SIGQUIT, func);
}
