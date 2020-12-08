/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:32:30 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/08 02:52:10 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_signs(char **new, t_list **tmp, int *res)
{
	if (**new == '<')
		ft_lstadd_back(tmp, ft_lstnew("<", 5, 0));
	if (**new == '>')
		ft_lstadd_back(tmp, ft_lstnew(">", 5, 0));
	if (**new == ';')
		ft_lstadd_back(tmp, ft_lstnew(";", 3, 0));
	if (**new == '|')
		ft_lstadd_back(tmp, ft_lstnew("|", 5, 0));
	*res += 1;
	*new += 1;
	if (**new)
		*res += words_get(new, tmp);
}

void ft_escape(char **new, t_list **tmp, int *res)
{
	char	*str;
	int		merge;

	*new += 1;
	str = ft_strndup(*new, 1);
	*new += 1;
	if (*new && **new != ' ' && **new != '\0')
		merge = 1;
	ft_lstadd_back(tmp, ft_lstnew(str, 0, merge));
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
	else if (* new && *new == ' ')
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

t_list *ft_merg(t_list *tmp)
{
	t_list	*new;
	t_list	*safe;
	t_list	*del;
	char	*tmp2;

	new = tmp;
	safe = NULL;
	ft_lstadd_back(&safe, ft_lstnew(ft_strdup(new->content), new->argument, new->merge));
	del = safe;
	if (tmp->next)
		tmp = tmp->next;
	else
		return (NULL);
	while (tmp->argument != 999)
	{
		if (safe->merge == 1 && tmp->argument != 3 && tmp->argument != 5)
		{
			tmp2 = safe->content;
			safe->content = ft_strjoin(safe->content, tmp->content);
			free(tmp2);
			safe->merge = new->merge;
		}
		else
			ft_lstadd_back(&safe, ft_lstnew(ft_strdup(tmp->content), tmp->argument, tmp->merge));
		if (tmp->argument == 5 || tmp->argument == 3)
			safe->merge = 0;
		tmp = tmp->next;
		new = new->next;
		if (safe->merge == 0)
			safe = safe->next;
	}
	return (del);
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
	ft_lstadd_back(&tmp, ft_lstnew(";", 999, 0));
	// getchar();
	new = ft_merg(tmp);
	ft_lstadd_back(&new, ft_lstnew(";", 999, 0));
	i = ft_tokens(new);

	safe = ft_parse_2(new);
	ft_exe(safe);
	// while (tmp->argument != 999)
	// {
	// 	free(tmp->content);
	// 	free(tmp);
	// 	tmp = tmp->next;
	// }
	// ft_list_clear(&tmp);
	// ft_list_clear(&new);
}
