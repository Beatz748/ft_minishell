/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:49:08 by tbeedril          #+#    #+#             */
/*   Updated: 2020/07/20 15:47:15 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_form_u(t_form *print)
{
	if (print->width < 0)
	{
		print->width = ft_abs(print->width);
		print->minus = 1;
		print->zero = 0;
	}
	if (print->acc == 1)
		print->zero = 0;
}

void	ft_minus_u(t_form *print, unsigned long long num, int *i, char *s)
{
	while ((*i)++ < 0)
		write(1, "0", 1);
	if (print->accuracy != 0 || num != 0)
		ft_putstr_fd(s, 1);
}

void	ft_print_flags_u(t_form *print, int *res)
{
	while (*res < print->width)
	{
		if (print->zero == 1 && print->accuracy != 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(*res)++;
	}
}
