/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:34:50 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/01 20:29:53 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_new_fd(t_list *cmd)
{
	int		fd;
	int		flag;

	flag = 0;
	if (!(ft_strcmp(cmd->content, ">>")))
		flag = 1;
	*cmd = *cmd->next;
	if (flag == 0)
		fd = open(cmd->content, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	else
		fd = open(cmd->content, O_RDWR | O_APPEND, 0777);
	return (fd);
}

void	ft_minishell2(char **full)
{
	char	*path;

	path = full[0];
	if ((code = execve(path, full, en)) == -1)
	{
		ft_error(2, full);
		_exit(42);
	}
}
