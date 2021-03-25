/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <tbeedril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:04:04 by kshantel          #+#    #+#             */
/*   Updated: 2020/12/12 21:39:42 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
	while (safe->next)
	{
		free(safe->cntent);
		safe = safe->next;
	}
	ft_clear_lists(safe, tmp, new);
}
