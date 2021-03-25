/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:42:14 by tbeedril          #+#    #+#             */
/*   Updated: 2020/07/20 15:49:51 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags(t_form *flags)
{
	flags->plus = 0;
	flags->minus = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->dies = 0;
	flags->width = 0;
	flags->accuracy = -1;
	flags->size = 0;
	flags->acc = 0;
}

void	check_flags(t_form *flags)
{
	while (ft_isflag(flags->str))
	{
		if (*(flags->str) == '-')
			flags->minus = 1;
		else if (*(flags->str) == '+')
			flags->plus = 1;
		else if (*(flags->str) == ' ')
			flags->space = 1;
		else if (*(flags->str) == '#')
			flags->dies = 1;
		else if (*(flags->str) == '0')
			flags->zero = 1;
		flags->str++;
	}
	if (flags->minus == 1)
		flags->zero = 0;
	if (flags->plus == 1)
		flags->space = 0;
}

void	check_width(t_form *flags)
{
	if (*(flags->str) == '*')
	{
		flags->width = va_arg(*(flags->arg), int);
		flags->str++;
		return ;
	}
	flags->width = ft_atoi(flags->str);
	while (ft_isdigit(*(flags->str)) > 0)
		flags->str++;
}

void	check_accuracy(t_form *flags)
{
	if (*(flags->str) != '.')
		return ;
	flags->str++;
	if (*(flags->str) == '*')
	{
		flags->accuracy = va_arg(*(flags->arg), int);
		flags->str++;
		if (flags->accuracy >= 0)
			flags->acc = 1;
		return ;
	}
	flags->accuracy = ft_atoi(flags->str);
	while (ft_isdigit(*(flags->str)) > 0)
		flags->str++;
	if (flags->accuracy >= 0)
		flags->acc = 1;
	return ;
}

void	check_size(t_form *flags)
{
	if (*(flags->str) == 'l')
	{
		flags->size = 1;
		flags->str++;
		if (*(flags->str) == 'l')
		{
			flags->size = 2;
			flags->str++;
		}
	}
	else if (*(flags->str) == 'h')
	{
		flags->size = 3;
		flags->str++;
		if (*(flags->str) == 'h')
		{
			flags->size = 4;
			flags->str++;
		}
	}
}
