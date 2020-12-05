/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useful.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:32:07 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/05 18:11:45 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_new_redi(t_list *cmd)
{
	int		fd;

	*cmd = *cmd->next;
	fd = open(cmd->content, O_RDONLY);
	if (cmd->argument != 999)
		*cmd = *cmd->next;
	return (fd);
}

void	ft_do1(t_exec *exe, t_list **cmd, int *flag)
{
	pipe(exe->pipefd);
	close((exe->pipefd2)[1]);
	if (!(ft_strcmp((*cmd)->content, ">")) ||
		!(ft_strcmp((*cmd)->content, ">>")))
	{
		(exe->pipefd)[1] = ft_new_fd((*cmd));
		if ((*cmd)->argument != 999)
			(*cmd) = (*cmd)->next;
	}
	else if (!(ft_strcmp((*cmd)->content, "<")))
	{
		exe->pipefd[0] = ft_new_redi(*cmd);
		(exe->pipefd2)[1] = STDOUT_FILENO;
	}
	ft_exec(exe->full, (exe->pipefd2)[0], (exe->pipefd)[1]);
	close((exe->pipefd2)[1]);
	(exe->y)--;
	*flag = 0;
}

void	ft_do2(t_exec *exe, t_list **cmd, int *flag, int how)
{
	pipe(exe->pipefd2);
	close((exe->pipefd)[1]);
	if (how)
		(exe->pipefd)[0] = STDIN_FILENO;
	if (!(ft_strcmp((*cmd)->content, ">")) || !(ft_strcmp((*cmd)->content, ">>")))
	{
		(exe->pipefd2)[1] = ft_new_fd((*cmd));
		if ((*cmd)->argument != 999)
			(*cmd) = (*cmd)->next;
	}
	else if (!(ft_strcmp((*cmd)->content, "<")))
	{
		exe->pipefd[0] = ft_new_redi(*cmd);
		(exe->pipefd2)[1] = STDOUT_FILENO;
	}
	ft_exec(exe->full, (exe->pipefd)[0], (exe->pipefd2)[1]);
	(exe->y)--;
	*flag = 1;
}

void	ft_do3(t_exec *exe, t_list **cmd, int *file)
{
	close((exe->pipefd2)[1]);
	if (!(ft_strcmp((*cmd)->content, ">")) || !(ft_strcmp((*cmd)->content, ">>")))
	{
		*file = ft_new_fd((*cmd));
		ft_exec((exe->full), (exe->pipefd2)[0], *file);
		close(*file);
		if ((*cmd)->argument != 999)
			(*cmd) = (*cmd)->next;
	}
	else if (!(ft_strcmp((*cmd)->content, "<")))
	{
		exe->pipefd[0] = ft_new_redi(*cmd);
		(exe->pipefd2)[1] = STDOUT_FILENO;
	}
	else
		ft_exec((exe->full), (exe->pipefd2)[0], STDOUT_FILENO);
	close((exe->pipefd2)[0]);
}

void	ft_do4(t_exec *exe, t_list **cmd, int *file, int how)
{
	close((exe->pipefd)[1]);
	if (how)
		(exe->pipefd)[0] = STDIN_FILENO;
	if (!(ft_strcmp((*cmd)->content, ">")) || !(ft_strcmp((*cmd)->content, ">>")))
	{
		*file = ft_new_fd((*cmd));
		ft_exec((exe->full), (exe->pipefd)[0], *file);
		close(*file);
		if ((*cmd)->argument != 999)
			(*cmd) = (*cmd)->next;
	}
	else if (!(ft_strcmp((*cmd)->content, "<")))
	{
		exe->pipefd[0] = ft_new_redi(*cmd);
		(exe->pipefd2)[1] = STDOUT_FILENO;
	}
	else
		ft_exec((exe->full), (exe->pipefd)[0], STDOUT_FILENO);
	if ((exe->pipefd)[0] != STDIN_FILENO)
		close((exe->pipefd)[0]);
}
