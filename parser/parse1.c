/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:21:48 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/08 16:46:47 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_new_word(char **new, t_list **tmp, int *res)
{
	char	*str;
	int		wordlen;
	int		merge;

	*res += 1;
	merge = 0;
	wordlen = 0;
	while (**new && **new != ' ' && **new != ';' && **new != '\''
	&& **new != '\"' && **new != '$' && **new != '>'
	&& **new != '<' && **new != '|' && **new != '\\')
	{
		(*new)++;
		wordlen++;
	}
	str = ft_strndup(*new - wordlen, wordlen);
	if (*new && **new != ' ' && **new != '\0')
		merge = 1;
	ft_lab(tmp, ft_lstnew(str, 0, merge));
	if (*new)
		*res += words_get(new, tmp);
}

void	ft_new_2quo(char **new, t_list **tmp, int *res)
{
	char	*str;
	int		wordlen;
	char	*tmp_str;
	int		merge;

	*res += 1;
	merge = 0;
	*new += 1;
	wordlen = 0;
	while (**new && **new != '\"')
	{
		*new += 1;
		wordlen += 1;
	}
	tmp_str = ft_strndup(*new - wordlen, wordlen);
	if (*tmp_str == '$' && wordlen == 1)
		str = ft_strdup("$");
	else
		str = ft_some_dol(tmp_str);
	free(tmp_str);
	if (++*new && **new != ' ' && **new != '\0')
		merge = 1;
	ft_lab(tmp, ft_lstnew(str, 0, merge));
	if (*new)
		*res += words_get(new, tmp);
}

void	ft_do_space(char **new, t_list **tmp, int *res)
{
	while (**new && **new == ' ' && **new != ';' && **new != '\''
	&& **new != '\"' && **new != '$' && **new != '>'
	&& **new != '<' && **new != '|')
		*new += 1;
	if (*new)
		*res += words_get(new, tmp);
}

void	ft_somet(int *merge, int *wordlen, int **res)
{
	**res += 1;
	*merge = 0;
	*wordlen = 1;
}

void	ft_sign_dollar(char **new, t_list **tmp, int *res)
{
	char	*str;
	char	*fin;
	int		wordlen;
	int		merge;

	*new += 1;
	ft_somet(&merge, &wordlen, &res);
	while (*new && **new && !ft_strchr("; \'\"$><|\\", **new))
	{
		*new += 1;
		wordlen += 1;
	}
	str = ft_strndup(*new - wordlen, wordlen);
	if (str[1] == '?')
		fin = ft_itoa(g_code);
	else if (*str == '$' && wordlen == 1)
		fin = ft_strdup("$");
	else
		fin = ft_strdup(ft_get_tiktok(str + 1));
	free(str);
	if (*new && **new != ' ' && **new != '\0')
		merge = 1;
	ft_lab(tmp, ft_lstnew(fin, 0, merge));
	if (**new)
		*res += words_get((new), tmp);
}
