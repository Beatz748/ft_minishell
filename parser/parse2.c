/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:32:30 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/08 07:41:11 by kshantel         ###   ########.fr       */
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

void	ft_handl1_merg(t_list *safe, t_list *tmp)
{
	char	*tmp2;

	tmp2 = safe->cntent;
	safe->cntent = ft_strjoin(safe->cntent, tmp->cntent);
	free(tmp2);
	safe->mrg = tmp->mrg;
}

t_list	*ft_merg(t_list *tmp)
{
	t_list	*new;
	t_list	*safe;
	t_list	*del;

	new = tmp;
	safe = NULL;
	ft_lab(&safe, ft_lstnew(ft_strdup(new->cntent), new->ag, new->mrg));
	del = safe;
	if (tmp->next)
		tmp = tmp->next;
	while (tmp->ag != 999)
	{
		if (safe->mrg == 1 && tmp->ag != 3 && tmp->ag != 5 && new->mrg)
			ft_handl1_merg(safe, tmp);
		else
		{
			ft_lab(&safe, ft_lstnew(ft_strdup(tmp->cntent), tmp->ag, tmp->mrg));
			safe = safe->next;
		}
		if (tmp->ag == 5 || tmp->ag == 3)
			safe->mrg = 0;
		tmp = tmp->next;
		new = new->next;
	}
	return (del);
}

void	ft_clear_lists(t_list *safe, t_list *tmp, t_list *new)
{
	while (safe->ag != 999)
	{
		free(safe->cntent);
		safe = safe->next;
	}
	while (tmp->ag != 999)
	{
		if (tmp->ag != 3 && tmp->ag != 5)
			free(tmp->cntent);
		free(tmp);
		tmp = tmp->next;
	}
	ft_list_clear(&tmp);
	ft_list_clear(&new);
}

void	ft_parse(char *line)
{
	t_list	*tmp;
	t_list	*new;
	t_list	*safe;
	int		size;
	int		i;

	tmp = NULL;
	new = NULL;
	size = words_get(&line, &tmp);
	ft_lab(&tmp, ft_lstnew(";", 999, 0));
	new = ft_merg(tmp);
	ft_lab(&new, ft_lstnew(";", 999, 0));
	i = ft_tokens(new);
	safe = ft_parse_2(new);
	ft_exe(safe);
	ft_clear_lists(safe, tmp, new);
}
