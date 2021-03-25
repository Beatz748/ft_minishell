/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:18:58 by tbeedril          #+#    #+#             */
/*   Updated: 2020/07/20 16:48:50 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_fl
{
	va_list			*arg;
	char			*str;
	int				minus;
	int				plus;
	int				space;
	int				dies;
	int				zero;
	int				width;
	int				accuracy;
	int				size;
	int				acc;
}					t_form;

void				set_flags(t_form *flags);
int					ft_isflag(char *str);
void				check_flags(t_form *flags);
void				check_width(t_form *flags);
void				check_accuracy(t_form *flags);
void				check_size(t_form *flags);
int					ft_put_int(t_form *print);
int					ft_put_int_l(t_form *print);
int					ft_put_int_ll(t_form *print);
int					ft_put_int_h(t_form *print);
int					ft_put_int_hh(t_form *print);
int					ft_put_type(t_form *tmp);
int					ft_put_type_l(t_form *tmp);
int					ft_put_type_llhh(t_form *tmp);
int					ft_put_c(t_form *print);
int					ft_put_c_l(t_form *print);
void				ft_put_null_s(t_form *print, char **s);
void				ft_put_null_sl(t_form *print, wchar_t **s);
void				ft_print_flags_s(t_form *print, int *len);
int					ft_put_s(t_form *print);
int					ft_put_s_l(t_form *print);
int					ft_istype(char *s);
int					ft_isflag(char *str);
int					ft_is_int(char c);
int					ft_abs(int a);
size_t				ft_wstrlen(wchar_t *s);
char				*ft_itoa_hex(unsigned long long n);
char				*ft_lltoa_u(long long int n);
char				*ft_lltoa_uu(unsigned long long n);
char				*ft_substr_format(char ***s);
int					ft_put_p(t_form *print);
void				ft_minus_di(t_form *print, long long num, int *i, char *s);
void				ft_form_di(t_form *print);
void				ft_print_flags_di(t_form *print, int *res, long long num);
int					ft_put_di(t_form *print);
int					ft_put_di_l(t_form *print);
int					ft_put_di_h(t_form *print);
int					ft_put_di_hh(t_form *print);
int					ft_put_di_ll(t_form *print);
void				ft_form_u(t_form *print);
void				ft_minus_u(t_form *print,
unsigned long long num, int *i, char *s);
void				ft_print_flags_u(t_form *print, int *res);
int					ft_put_u_l(t_form *print);
int					ft_put_u_ll(t_form *print);
int					ft_put_u_h(t_form *print);
int					ft_put_u_hh(t_form *print);
int					ft_put_u(t_form *print);
void				ft_toupper_x(t_form *print, char **s);
void				ft_form_x(t_form *print);
int					ft_minus_x(t_form *print, unsigned long long num,
		int *i, char *s);
void				ft_print_flags_x(t_form *print, int *res);
int					ft_put_x(t_form *print);
int					ft_put_x_l(t_form *print);
int					ft_put_x_ll(t_form *print);
int					ft_put_x_h(t_form *print);
int					ft_put_x_hh(t_form *print);
int					ft_put_value(t_form *print, int *res, char **s);
int					ft_format(t_form *print);
int					ft_putformat(const char **format, va_list *argptr);
int					ft_printf(const char *format, ...);

#endif
