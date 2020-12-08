/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:45:01 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/08 06:31:51 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

void	ft_free_unset(t_list2 *srch)
{
	free(srch->name);
	free(srch->content);
	free(srch);
}

int		ft_unset(char **full)
{
	int		i;
	t_list2	*tmp;
	t_list2	*srch;

	i = 1;
	while (full[i])
	{
		if (!(ft_strcmp(full[i], "_")))
			i++;
		else
		{
			tmp = g_env;
			while (tmp && ft_strcmp(tmp->next->name, full[i]) != 0)
				tmp = tmp->next;
			if (tmp)
			{
				srch = tmp->next;
				tmp->next = srch->next;
				ft_free_unset(srch);
			}
			i++;
		}
	}
	g_code = 0;
	return (0);
}
