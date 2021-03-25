/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:37:18 by tbeedril          #+#    #+#             */
/*   Updated: 2020/07/20 17:00:57 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_int(t_form *print)
{
	if (*(print->str) == 'd' || *(print->str) == 'i')
		return (ft_put_di(print));
	if (*(print->str) == 'u')
		return (ft_put_u(print));
	if (*(print->str) == 'x' || *(print->str) == 'X')
		return (ft_put_x(print));
	return (0);
}

int	ft_put_int_l(t_form *print)
{
	if (*(print->str) == 'd' || *(print->str) == 'i')
		return (ft_put_di_l(print));
	if (*(print->str) == 'u')
		return (ft_put_u_l(print));
	if (*(print->str) == 'x' || *(print->str) == 'X')
		return (ft_put_x_l(print));
	return (0);
}

int	ft_put_int_ll(t_form *print)
{
	if (*(print->str) == 'd' || *(print->str) == 'i')
		return (ft_put_di_ll(print));
	if (*(print->str) == 'u')
		return (ft_put_u_ll(print));
	if (*(print->str) == 'x' || *(print->str) == 'X')
		return (ft_put_x_ll(print));
	return (0);
}

int	ft_put_int_h(t_form *print)
{
	if (*(print->str) == 'd' || *(print->str) == 'i')
		return (ft_put_di_h(print));
	if (*(print->str) == 'u')
		return (ft_put_u_h(print));
	if (*(print->str) == 'x' || *(print->str) == 'X')
		return (ft_put_x_h(print));
	return (0);
}

int	ft_put_int_hh(t_form *print)
{
	if (*(print->str) == 'd' || *(print->str) == 'i')
		return (ft_put_di_hh(print));
	if (*(print->str) == 'u')
		return (ft_put_u_hh(print));
	if (*(print->str) == 'x' || *(print->str) == 'X')
		return (ft_put_x_hh(print));
	return (0);
}
