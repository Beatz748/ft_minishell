/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:49:54 by tbeedril          #+#    #+#             */
/*   Updated: 2020/07/20 16:47:52 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_x(t_form *print)
{
	int				res;
	unsigned int	num;
	char			*s;
	int				i;

	res = 0;
	num = va_arg(*(print->arg), unsigned int);
	ft_form_x(print);
	if (!(s = ft_itoa_hex((unsigned long long)num)))
		return (-1);
	ft_toupper_x(print, &s);
	i = ft_strlen(s);
	i = (i == print->accuracy) ? i : i - print->accuracy;
	res = (i < 0) ? print->accuracy : (int)ft_strlen(s);
	if (print->accuracy == 0 && num == 0)
		res = 0;
	if (print->minus == 1)
		res += ft_minus_x(print, (unsigned long long)num, &i, s);
	ft_print_flags_x(print, &res);
	if (print->minus == 0)
		res += ft_minus_x(print, (unsigned long long)num, &i, s);
	free(s);
	return (res);
}

int	ft_put_x_l(t_form *print)
{
	int					res;
	unsigned long int	num;
	char				*s;
	int					i;

	res = 0;
	num = va_arg(*(print->arg), unsigned long int);
	ft_form_x(print);
	if (!(s = ft_itoa_hex((unsigned long long)num)))
		return (-1);
	ft_toupper_x(print, &s);
	i = ft_strlen(s);
	i = (i == print->accuracy) ? i : i - print->accuracy;
	res = (i < 0) ? print->accuracy : (int)ft_strlen(s);
	if (print->accuracy == 0 && num == 0)
		res = 0;
	if (print->minus == 1)
		res += ft_minus_x(print, (unsigned long long)num, &i, s);
	ft_print_flags_x(print, &res);
	if (print->minus == 0)
		res += ft_minus_x(print, (unsigned long long)num, &i, s);
	free(s);
	return (res);
}

int	ft_put_x_ll(t_form *print)
{
	int					res;
	unsigned long long	num;
	char				*s;
	int					i;

	res = 0;
	num = va_arg(*(print->arg), unsigned long long);
	ft_form_x(print);
	if (!(s = ft_itoa_hex(num)))
		return (-1);
	ft_toupper_x(print, &s);
	i = ft_strlen(s);
	i = (i == print->accuracy) ? i : i - print->accuracy;
	res = (i < 0) ? print->accuracy : (int)ft_strlen(s);
	if (print->accuracy == 0 && num == 0)
		res = 0;
	if (print->minus == 1)
		res += ft_minus_x(print, num, &i, s);
	ft_print_flags_x(print, &res);
	if (print->minus == 0)
		res += ft_minus_x(print, num, &i, s);
	free(s);
	return (res);
}

int	ft_put_x_h(t_form *print)
{
	int					res;
	unsigned short int	num;
	char				*s;
	int					i;

	res = 0;
	num = (unsigned short int)va_arg(*(print->arg), int);
	ft_form_x(print);
	if (!(s = ft_itoa_hex((unsigned long long)num)))
		return (-1);
	ft_toupper_x(print, &s);
	i = ft_strlen(s);
	i = (i == print->accuracy) ? i : i - print->accuracy;
	res = (i < 0) ? print->accuracy : (int)ft_strlen(s);
	if (print->accuracy == 0 && num == 0)
		res = 0;
	if (print->minus == 1)
		res += ft_minus_x(print, (unsigned long long)num, &i, s);
	ft_print_flags_x(print, &res);
	if (print->minus == 0)
		res += ft_minus_x(print, (unsigned long long)num, &i, s);
	free(s);
	return (res);
}

int	ft_put_x_hh(t_form *print)
{
	int				res;
	unsigned char	num;
	char			*s;
	int				i;

	res = 0;
	num = (unsigned char)va_arg(*(print->arg), int);
	ft_form_x(print);
	if (!(s = ft_itoa_hex((unsigned long long)num)))
		return (-1);
	ft_toupper_x(print, &s);
	i = ft_strlen(s);
	i = (i == print->accuracy) ? i : i - print->accuracy;
	res = (i < 0) ? print->accuracy : (int)ft_strlen(s);
	if (print->accuracy == 0 && num == 0)
		res = 0;
	if (print->minus == 1)
		res += ft_minus_x(print, (unsigned long long)num, &i, s);
	ft_print_flags_x(print, &res);
	if (print->minus == 0)
		res += ft_minus_x(print, (unsigned long long)num, &i, s);
	free(s);
	return (res);
}
