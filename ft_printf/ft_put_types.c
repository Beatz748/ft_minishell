/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:34:10 by tbeedril          #+#    #+#             */
/*   Updated: 2020/07/20 15:47:45 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_type(t_form *tmp)
{
	if (*(tmp->str) == 'c' || *(tmp->str) == '%')
		return (ft_put_c(tmp));
	if (*(tmp->str) == 's')
		return (ft_put_s(tmp));
	if (*(tmp->str) == 'p')
		return (ft_put_p(tmp));
	if (ft_is_int(*(tmp->str)))
		return (ft_put_int(tmp));
	return (0);
}

int	ft_put_type_l(t_form *tmp)
{
	if (*(tmp->str) == 'c' || *(tmp->str) == '%')
		return (ft_put_c_l(tmp));
	if (*(tmp->str) == 's')
		return (ft_put_s_l(tmp));
	if (ft_is_int(*(tmp->str)))
		return (ft_put_int_l(tmp));
	return (0);
}

int	ft_put_type_llhh(t_form *tmp)
{
	if (ft_is_int(*(tmp->str)) && tmp->size == 2)
		return (ft_put_int_ll(tmp));
	if (ft_is_int(*(tmp->str)) && tmp->size == 3)
		return (ft_put_int_h(tmp));
	if (ft_is_int(*(tmp->str)) && tmp->size == 4)
		return (ft_put_int_hh(tmp));
	return (0);
}
