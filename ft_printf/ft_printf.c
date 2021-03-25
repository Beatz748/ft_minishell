/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:08:36 by tbeedril          #+#    #+#             */
/*   Updated: 2020/07/20 16:51:10 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(t_form *print)
{
	int res;

	res = 0;
	set_flags(print);
	check_flags(print);
	check_width(print);
	check_accuracy(print);
	check_size(print);
	if (print->accuracy == -1 && ft_is_int(*(print->str)) == 1)
		print->accuracy = 1;
	if (print->size == 1)
		res += ft_put_type_l(print);
	else if (print->size == 0)
		res += ft_put_type(print);
	else
		res += ft_put_type_llhh(print);
	return (res);
}

int	ft_put_value(t_form *print, int *res, char **s)
{
	int		res2;
	char	*str;

	(*s)++;
	if (**s == '%')
	{
		write(1, (*s)++, 1);
		(*res) += 1;
		return (0);
	}
	if (!(str = ft_substr_format(&s)))
	{
		free(print);
		return (-1);
	}
	print->str = str;
	res2 = ft_format(print);
	free(str);
	if (res2 == -1)
	{
		free(print);
		return (-1);
	}
	*res += res2;
	return (0);
}

int	ft_putformat(const char **format, va_list *argptr)
{
	int		res;
	char	*s;
	t_form	*print;

	res = 0;
	s = (char *)*format;
	if (!(print = (t_form *)malloc(sizeof(t_form))))
		return (-1);
	print->arg = argptr;
	while (*s)
	{
		if (*(s) == '%' && ft_put_value(print, &res, &s) == -1)
			return (-1);
		else if (*(s) != '%' && *s)
		{
			write(1, s, 1);
			s++;
			res++;
		}
	}
	free(print);
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		res;
	va_list	argptr;

	res = 0;
	if (!format)
	{
		write(1, "(null)", 6);
		return (0);
	}
	va_start(argptr, format);
	if ((res = ft_putformat(&format, &argptr)) == -1)
		return (-1);
	va_end(argptr);
	return (res);
}
