/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_di_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:35:16 by tbeedril          #+#    #+#             */
/*   Updated: 2020/07/20 15:48:18 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minus_di(t_form *print, long long num, int *i, char *s)
{
	if (num < 0 && print->zero == 0)
		write(1, "-", 1);
	if (print->plus == 1 && num >= 0 && print->zero == 0)
		write(1, "+", 1);
	if (print->space == 1 && num >= 0 && print->zero == 0)
		write(1, " ", 1);
	while ((*i)++ < 0)
		write(1, "0", 1);
	if (print->accuracy != 0 || num != 0)
		ft_putstr_fd(s, 1);
}

void	ft_form_di(t_form *print)
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

void	ft_print_flags_di(t_form *print, int *res, long long num)
{
	if (print->zero == 1)
	{
		if (num < 0)
			write(1, "-", 1);
		if (print->plus == 1 && num >= 0)
			write(1, "+", 1);
		if (print->space == 1 && num >= 0)
			write(1, " ", 1);
	}
	while (*res < print->width)
	{
		if (print->zero == 1 && print->accuracy != 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(*res)++;
	}
}
