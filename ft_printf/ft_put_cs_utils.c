/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cs_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 18:10:37 by tbeedril          #+#    #+#             */
/*   Updated: 2020/07/20 15:48:48 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_null_s(t_form *print, char **s)
{
	if (print->accuracy < 6 && print->accuracy != -1)
		*s = "\0";
	else
		*s = "(null)";
}

void	ft_put_null_sl(t_form *print, wchar_t **s)
{
	if (print->accuracy < 6 && print->accuracy != -1)
		*s = L"\0";
	else
		*s = L"(null)";
}

void	ft_print_flags_s(t_form *print, int *len)
{
	if (print->width < 0)
	{
		print->width = ft_abs(print->width);
		print->minus = 1;
		print->zero = 0;
	}
	if (print->accuracy > -1)
		*len = (print->accuracy > *len) ? *len : print->accuracy;
}
