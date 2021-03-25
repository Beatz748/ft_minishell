/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:25:50 by tbeedril          #+#    #+#             */
/*   Updated: 2020/07/20 15:48:36 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_di(t_form *print)
{
	int		res;
	char	*s;
	int		i;
	int		num;

	num = va_arg(*(print->arg), int);
	ft_form_di(print);
	if (!(s = ft_lltoa_u((long long)num)))
		return (-1);
	i = ft_strlen(s);
	i = (i == print->accuracy) ? i : i - print->accuracy;
	res = (i < 0) ? print->accuracy : (int)ft_strlen(s);
	res = (num < 0 || print->plus == 1 || print->space == 1) ? res + 1 : res;
	if (print->accuracy == 0 && num == 0)
		res = 0;
	if (print->minus == 1)
		ft_minus_di(print, (long long)num, &i, s);
	ft_print_flags_di(print, &res, (long long)num);
	if (print->minus == 0)
		ft_minus_di(print, (long long)num, &i, s);
	free(s);
	return (res);
}

int	ft_put_di_l(t_form *print)
{
	int			res;
	char		*s;
	int			i;
	long int	num;

	num = va_arg(*(print->arg), long int);
	ft_form_di(print);
	if (!(s = ft_lltoa_u((long long)num)))
		return (-1);
	i = ft_strlen(s);
	i = (i == print->accuracy) ? i : i - print->accuracy;
	res = (i < 0) ? print->accuracy : (int)ft_strlen(s);
	res = (num < 0 || print->plus == 1 || print->space == 1) ? res + 1 : res;
	if (print->accuracy == 0 && num == 0)
		res = 0;
	if (print->minus == 1)
		ft_minus_di(print, (long long)num, &i, s);
	ft_print_flags_di(print, &res, (long long)num);
	if (print->minus == 0)
		ft_minus_di(print, (long long)num, &i, s);
	free(s);
	return (res);
}

int	ft_put_di_ll(t_form *print)
{
	int			res;
	char		*s;
	int			i;
	long long	num;

	num = va_arg(*(print->arg), long long);
	ft_form_di(print);
	if (!(s = ft_lltoa_u(num)))
		return (-1);
	i = ft_strlen(s);
	i = (i == print->accuracy) ? i : i - print->accuracy;
	res = (i < 0) ? print->accuracy : (int)ft_strlen(s);
	res = (num < 0 || print->plus == 1 || print->space == 1) ? res + 1 : res;
	if (print->accuracy == 0 && num == 0)
		res = 0;
	if (print->minus == 1)
		ft_minus_di(print, num, &i, s);
	ft_print_flags_di(print, &res, num);
	if (print->minus == 0)
		ft_minus_di(print, num, &i, s);
	free(s);
	return (res);
}

int	ft_put_di_h(t_form *print)
{
	int			res;
	char		*s;
	int			i;
	short int	num;

	num = (short int)va_arg(*(print->arg), int);
	ft_form_di(print);
	if (!(s = ft_lltoa_u((long long)num)))
		return (-1);
	i = ft_strlen(s);
	i = (i == print->accuracy) ? i : i - print->accuracy;
	res = (i < 0) ? print->accuracy : (int)ft_strlen(s);
	res = (num < 0 || print->plus == 1 || print->space == 1) ? res + 1 : res;
	if (print->accuracy == 0 && num == 0)
		res = 0;
	if (print->minus == 1)
		ft_minus_di(print, (long long)num, &i, s);
	ft_print_flags_di(print, &res, (long long)num);
	if (print->minus == 0)
		ft_minus_di(print, (long long)num, &i, s);
	free(s);
	return (res);
}

int	ft_put_di_hh(t_form *print)
{
	int			res;
	char		*s;
	int			i;
	signed char	num;

	num = (signed char)va_arg(*(print->arg), int);
	ft_form_di(print);
	if (!(s = ft_lltoa_u((long long)num)))
		return (-1);
	i = ft_strlen(s);
	i = (i == print->accuracy) ? i : i - print->accuracy;
	res = (i < 0) ? print->accuracy : (int)ft_strlen(s);
	res = (num < 0 || print->plus == 1 || print->space == 1) ? res + 1 : res;
	if (print->accuracy == 0 && num == 0)
		res = 0;
	if (print->minus == 1)
		ft_minus_di(print, (long long)num, &i, s);
	ft_print_flags_di(print, &res, (long long)num);
	if (print->minus == 0)
		ft_minus_di(print, (long long)num, &i, s);
	free(s);
	return (res);
}
