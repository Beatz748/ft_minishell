/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:37:39 by tbeedril          #+#    #+#             */
/*   Updated: 2020/07/20 15:47:32 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_u(t_form *print)
{
	int				res;
	char			*s;
	int				i;
	unsigned int	num;

	num = va_arg(*(print->arg), unsigned int);
	ft_form_u(print);
	if (!(s = ft_lltoa_uu((unsigned long long)num)))
		return (-1);
	i = ft_strlen(s);
	i = (i == print->accuracy) ? i : i - print->accuracy;
	res = (i < 0) ? print->accuracy : (int)ft_strlen(s);
	if (print->accuracy == 0 && num == 0)
		res = 0;
	if (print->minus == 1)
		ft_minus_u(print, (unsigned long long)num, &i, s);
	ft_print_flags_u(print, &res);
	if (print->minus == 0)
		ft_minus_u(print, (unsigned long long)num, &i, s);
	free(s);
	return (res);
}

int	ft_put_u_l(t_form *print)
{
	int					res;
	char				*s;
	int					i;
	unsigned long int	num;

	num = va_arg(*(print->arg), unsigned long int);
	ft_form_u(print);
	if (!(s = ft_lltoa_uu((unsigned long long)num)))
		return (-1);
	i = ft_strlen(s);
	i = (i == print->accuracy) ? i : i - print->accuracy;
	res = (i < 0) ? print->accuracy : (int)ft_strlen(s);
	if (print->accuracy == 0 && num == 0)
		res = 0;
	if (print->minus == 1)
		ft_minus_u(print, (unsigned long long)num, &i, s);
	ft_print_flags_u(print, &res);
	if (print->minus == 0)
		ft_minus_u(print, (unsigned long long)num, &i, s);
	free(s);
	return (res);
}

int	ft_put_u_ll(t_form *print)
{
	int					res;
	char				*s;
	int					i;
	unsigned long long	num;

	num = va_arg(*(print->arg), unsigned long long);
	ft_form_u(print);
	if (!(s = ft_lltoa_uu(num)))
		return (-1);
	i = ft_strlen(s);
	i = (i == print->accuracy) ? i : i - print->accuracy;
	res = (i < 0) ? print->accuracy : (int)ft_strlen(s);
	if (print->accuracy == 0 && num == 0)
		res = 0;
	if (print->minus == 1)
		ft_minus_u(print, num, &i, s);
	ft_print_flags_u(print, &res);
	if (print->minus == 0)
		ft_minus_u(print, num, &i, s);
	free(s);
	return (res);
}

int	ft_put_u_h(t_form *print)
{
	int					res;
	char				*s;
	int					i;
	unsigned short int	num;

	num = (unsigned short int)va_arg(*(print->arg), int);
	ft_form_u(print);
	if (!(s = ft_lltoa_uu((unsigned long long)num)))
		return (-1);
	i = ft_strlen(s);
	i = (i == print->accuracy) ? i : i - print->accuracy;
	res = (i < 0) ? print->accuracy : (int)ft_strlen(s);
	if (print->accuracy == 0 && num == 0)
		res = 0;
	if (print->minus == 1)
		ft_minus_u(print, (unsigned long long)num, &i, s);
	ft_print_flags_u(print, &res);
	if (print->minus == 0)
		ft_minus_u(print, (unsigned long long)num, &i, s);
	free(s);
	return (res);
}

int	ft_put_u_hh(t_form *print)
{
	int				res;
	char			*s;
	int				i;
	unsigned char	num;

	num = (unsigned char)va_arg(*(print->arg), int);
	ft_form_u(print);
	if (!(s = ft_lltoa_uu((unsigned long long)num)))
		return (-1);
	i = ft_strlen(s);
	i = (i == print->accuracy) ? i : i - print->accuracy;
	res = (i < 0) ? print->accuracy : (int)ft_strlen(s);
	if (print->accuracy == 0 && num == 0)
		res = 0;
	if (print->minus == 1)
		ft_minus_u(print, (unsigned long long)num, &i, s);
	ft_print_flags_u(print, &res);
	if (print->minus == 0)
		ft_minus_u(print, (unsigned long long)num, &i, s);
	free(s);
	return (res);
}
