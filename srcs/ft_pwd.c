/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:51:40 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/08 06:03:53 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

int		ft_exec_pwd(char **full)
{
	(void)full;
	write(1, getcwd(NULL, 0), ft_strlen(getcwd(NULL, 0)));
	write(1, "\n", 1);
	g_code = 0;
	return (0);
}
