/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:32:30 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/01 18:25:50 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_signs(char **new, t_list **tmp, int *res)
{
	if (**new == '<')
		ft_lstadd_back(tmp, ft_lstnew("<", 5));
	if (**new == '>')
		ft_lstadd_back(tmp, ft_lstnew(">", 5));
	if (**new == ';')
		ft_lstadd_back(tmp, ft_lstnew(";", 3));
	if (**new == '|')
		ft_lstadd_back(tmp, ft_lstnew("|", 5));
	*res += 1;
	*new += 1;
	if (**new)
		*res += words_get(new, tmp);
}

int		words_get(char **s, t_list **tmp)
{
	int		res;
	char	*new;

	res = 0;
	if (!(s) || !(*s) || !(**s) || !(new = *s))
		return (0);
	if (*new && *new == '\'')
		ft_new_1quo(&new, tmp, &res);
	else if (*new && *new == '\"')
		ft_new_2quo(&new, tmp, &res);
	else if (*new && *new != ' ' && *new != ';' && *new != '$'
	&& *new != '>' && *new != '<' && *new != '|')
		ft_new_word(&new, tmp, &res);
	else if (* new && *new == ' ')
		ft_do_space(&new, tmp, &res);
	else if (*new == ';' || *new == '<' || *new == '>' || *new == '|')
		ft_signs(&new, tmp, &res);
	else if (*new && *new == '$')
		ft_sign_dollar(&new, tmp, &res);
	return (res);
}

int		ft_tokens(t_list *cmd)
{
	int		tok;

	tok = 1;
	while (cmd)
	{
		if (cmd->argument == 1)
			tok++;
		cmd = cmd->next;
	}
	return (tok);
}

t_list	*ft_parse_2(t_list *cmd)
{
	t_list	*tmp;
	t_list	*ret;

	tmp = (cmd->argument != 999) ? cmd->next : cmd;
	ret = cmd;
	while (tmp->argument != 999)
	{
		if (cmd->argument == 5 && !ft_strcmp(tmp->content, ">"))
		{
			cmd->content = ft_strjoin(cmd->content, tmp->content);
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

void	ft_parse(char *line)
{
	t_list	*tmp;
	int		size;
	int		i;

	tmp = NULL;
	size = words_get(&line, &tmp);
	ft_lstadd_back(&tmp, ft_lstnew(";", 999));
	i = ft_tokens(tmp);
	tmp = ft_parse_2(tmp);
	ft_exe(tmp);
	ft_list_clear(&tmp);
}
