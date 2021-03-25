/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:52:10 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/08 06:03:53 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

int		ft_exit(char **full)
{
	int		i;

	i = 0;
	if (full[1])
		i = ft_atoi(full[1]);
	g_code = i;
	exit(g_code);
	return (i);
}
