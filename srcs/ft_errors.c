/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:07:28 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/02 17:57:41 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(int i, char **full)
{
	write(1, "\033[1;31m", 8);
	if (i == 1)
		write(1, " Unable to fork =( ", 20);
	if (i == 228)
		write(1, "unable features", 16);
	if (i == 2)
	{
		code = 127;
		ft_putstr_fd("pizza-shell: command not found: ", 1);
		ft_putstr_fd(full[0], 1);
	}
	if (i == 3)
		ft_putstr_fd("something went wrong", 1);
	write(1, "\033[0m \n", 7);
}

void	ft_error2(int i)
{
	if (i == 3)
		ft_putstr_fd("something went wrong", 1);
	write(1, "\033[0m \n", 7);
}
