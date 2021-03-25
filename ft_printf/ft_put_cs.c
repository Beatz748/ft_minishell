/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:39:37 by tbeedril          #+#    #+#             */
/*   Updated: 2020/07/20 16:05:40 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_c(t_form *print)
{
	int				res;
	unsigned char	c;

	res = 1;
	if ((print->str)[0] != '%')
		c = (unsigned char)va_arg(*(print->arg), int);
	else
		c = '%';
	if (print->minus == 1)
		write(1, &c, 1);
	while (res < print->width)
	{
		if (print->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		res++;
	}
	if (print->minus == 0)
		write(1, &c, 1);
	return (res);
}

int	ft_put_c_l(t_form *print)
{
	int		res;
	wchar_t	c;

	res = 1;
	if ((print->str)[0] != '%')
		c = (wchar_t)va_arg(*(print->arg), int);
	else
		c = L'%';
	if (print->minus == 1)
		write(1, &c, 1);
	while (res < print->width)
	{
		write(1, " ", 1);
		res++;
	}
	if (print->minus == 0)
		write(1, &c, 1);
	return (res);
}

int	ft_put_s(t_form *print)
{
	char	*s;
	int		res;
	int		len;

	if (!(s = va_arg(*(print->arg), char *)))
		s = "(null)";
	len = ft_strlen(s);
	ft_print_flags_s(print, &len);
	res = len;
	while (print->minus == 1 && len--)
	{
		write(1, s, 1);
		s++;
	}
	while (res < print->width)
	{
		write(1, " ", 1);
		res++;
	}
	while (print->minus == 0 && len--)
	{
		write(1, s, 1);
		s++;
	}
	return (res);
}

int	ft_put_s_l(t_form *print)
{
	wchar_t	*s;
	int		res;
	int		len;

	if (!(s = va_arg(*(print->arg), wchar_t *)))
		s = L"(null)";
	len = ft_wstrlen(s);
	ft_print_flags_s(print, &len);
	res = len;
	while (print->minus == 1 && len--)
	{
		write(1, s, 1);
		s++;
	}
	while (res < print->width)
	{
		write(1, " ", 1);
		res++;
	}
	while (print->minus == 0 && len--)
	{
		write(1, s, 1);
		s++;
	}
	return (res);
}

int	ft_put_p(t_form *print)
{
	int					res;
	unsigned long long	p;
	char				*s;

	p = va_arg(*(print->arg), unsigned long long);
	if (!(s = ft_itoa_hex(p)))
		return (-1);
	res = ft_strlen(s) + 2;
	if (print->minus == 1)
	{
		write(1, "0x", 2);
		ft_putstr_fd(s, 1);
	}
	while (res < print->width)
	{
		write(1, " ", 1);
		res++;
	}
	if (print->minus == 0)
	{
		write(1, "0x", 2);
		ft_putstr_fd(s, 1);
	}
	free(s);
	return (res);
}
