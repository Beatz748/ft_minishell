/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:34:50 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/08 07:34:52 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del(lst->cntent);
	free(lst);
}

int		ft_new_fd(t_list **cmd)
{
	int		fd;
	int		flag;

	flag = 0;
	if (!(ft_strcmp((*cmd)->cntent, ">>")))
		flag = 1;
	(*cmd) = (*cmd)->next;
	if (flag == 0)
		fd = open((*cmd)->cntent, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	else
		fd = open((*cmd)->cntent, O_RDWR | O_APPEND, 0777);
	return (fd);
}

void	ft_minishell2(char **full)
{
	char	*path;

	path = full[0];
	if (execve(path, full, g_en) == -1)
	{
		ft_error(2, full);
		exit(g_code);
	}
}
