/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:07:37 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/20 19:15:47 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	int	i;

	if (!(g_env = env))
		exit(-1);
	write(1, "\033[0;31mpizza-shell ", 20);
	write(1, "BY TBEEDRIL && KSHANTEL 🍕 \033[0m \n\n\n", 38);
	ft_minishell();
}
