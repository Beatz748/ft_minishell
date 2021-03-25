/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:02:08 by tbeedril          #+#    #+#             */
/*   Updated: 2020/07/20 16:48:28 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_toupper_x(t_form *print, char **s)
{
	int i;

	i = 0;
	while (s[0][i] && *(print->str) == 'X')
	{
		s[0][i] = ft_toupper(s[0][i]);
		i++;
	}
}

void	ft_form_x(t_form *print)
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

int		ft_minus_x(t_form *print, unsigned long long num,
		int *i, char *s)
{
	int res;

	res = 0;
	if (print->dies == 1)
		(*(print->str) == 'x') ? write(1, "0x", 2) : write(1, "0X", 2);
	while ((*i)++ < 0)
		write(1, "0", 1);
	if (print->accuracy != 0 || num != 0)
		ft_putstr_fd(s, 1);
	if (print->dies == 1)
		res += 2;
	return (res);
}

void	ft_print_flags_x(t_form *print, int *res)
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
