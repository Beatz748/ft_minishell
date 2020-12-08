/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:18:44 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/08 06:29:37 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "../utils/utils.h"
# include "../srcs/minishell.h"

typedef struct	s_dol
{
	int		i;
	int		j;
	char	*sub;
	char	*s;
	char	*tmp;
}				t_dol;

void			ft_new_1quo(char **new, t_list **tmp, int *res);
void			ft_new_word(char **new, t_list **tmp, int *res);
void			ft_new_2quo(char **new, t_list **tmp, int *res);
void			ft_do_space(char **new, t_list **tmp, int *res);
void			ft_sign_dollar(char **new, t_list **tmp, int *res);
void			ft_signs(char **new, t_list **tmp, int *res);
int				words_get(char **s, t_list **tmp);
int				ft_tokens(t_list *cmd);
t_list			*ft_parse_2(t_list *cmd);
void			ft_parse(char *line);
char			*ft_some_dol(char *str);
t_list2			*ft_parse_env(char **env);
void			ft_now(t_list *tmp);
char			*ft_get_tiktok(char *str);
char			*ft_get_gome();

#endif
