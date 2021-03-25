/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:38:51 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/08 06:03:53 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

int		ft_echo(char **full)
{
	int i;

	i = 1;
	while (full[i] && !ft_strcmp(full[i], "-n"))
		i++;
	while (full[i] != NULL)
	{
		ft_putstr_fd(full[i], 1);
		if (full[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (full[1] && ft_strcmp(full[1], "-n"))
		write(1, "\n", 1);
	g_code = 0;
	return (0);
}
