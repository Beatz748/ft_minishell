/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <tbeedril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:32:30 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/12 21:38:39 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_signs(char **new, t_list **tmp, int *res)
{
	if (**new == '<')
		ft_lab(tmp, ft_lstnew("<", 5, 0));
	if (**new == '>')
		ft_lab(tmp, ft_lstnew(">", 5, 0));
	if (**new == ';')
		ft_lab(tmp, ft_lstnew(";", 3, 0));
	if (**new == '|')
		ft_lab(tmp, ft_lstnew("|", 5, 0));
	*res += 1;
	*new += 1;
	if (**new)
		*res += words_get(new, tmp);
}

void	ft_escape(char **new, t_list **tmp, int *res)
{
	char	*str;
	int		merge;

	merge = 0;
	*new += 1;
	str = ft_strndup(*new, 1);
	*new += 1;
	if (*new && **new != ' ' && **new != '\0')
		merge = 1;
	ft_lab(tmp, ft_lstnew(str, 0, merge));
	if (**new)
		*res += words_get(new, tmp);
}

int		words_get(char **s, t_list **tmp)
{
	int		res;
	char	*new;

	res = 0;
	if (!(s) || !(*s) || !(new = *s))
		return (0);
	if (*new && *new == '\'')
		ft_new_1quo(&new, tmp, &res);
	else if (*new && *new == '\"')
		ft_new_2quo(&new, tmp, &res);
	else if (*new && *new != ' ' && *new != ';' && *new != '$'
	&& *new != '>' && *new != '<' && *new != '|' && *new != '\\')
		ft_new_word(&new, tmp, &res);
	else if (*new && *new == ' ')
		ft_do_space(&new, tmp, &res);
	else if (*new == ';' || *new == '<' || *new == '>' || *new == '|')
		ft_signs(&new, tmp, &res);
	else if (*new && *new == '$')
		ft_sign_dollar(&new, tmp, &res);
	else if (*new && *new == '\\')
		ft_escape(&new, tmp, &res);
	return (res);
}

int		ft_tokens(t_list *cmd)
{
	int		tok;

	tok = 1;
	while (cmd)
	{
		if (cmd->ag == 1)
			tok++;
		cmd = cmd->next;
	}
	return (tok);
}

t_list	*ft_parse_2(t_list *cmd)
{
	t_list	*tmp;
	t_list	*ret;

	tmp = (cmd->ag != 999) ? cmd->next : cmd;
	ret = cmd;
	while (tmp->ag != 999)
	{
		if (cmd->ag == 5 && !ft_strcmp(tmp->cntent, ">"))
		{
			cmd->cntent = ft_strjoin(cmd->cntent, tmp->cntent);
			cmd->next = tmp->next;
			tmp = tmp->next;
		}
		if (tmp->next)
		{
			tmp = tmp->next;
			cmd = cmd->next;
		}
		else
			break ;
	}
	return (ret);
}
