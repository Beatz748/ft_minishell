/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:09:11 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/08 16:45:03 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init(t_exec *exe, t_list *cmd, int *flag)
{
	pipe(exe->pipefd);
	pipe(exe->pipefd2);
	exe->y = ft_list_pipes(cmd);
	*flag = 0;
}

int		ft_full_init(t_exec *exe, t_list **cmd)
{
	int		i;
	char	**auf;

	i = 0;
	exe->size_mini = ft_len(*cmd);
	if (!(auf = malloc((sizeof(char *)) * (exe->size_mini + 1))))
		return (1);
	while (i < exe->size_mini)
	{
		auf[i] = ft_strdup((*cmd)->cntent);
		*cmd = (*cmd)->next;
		i++;
	}
	auf[i] = NULL;
	exe->full = auf;
	return (0);
}

void	ft_exec2(char **full)
{
	pid_t	pid;
	int		status;

	if (full[0] == NULL)
		return ;
	else if (!(ft_strcmp(full[0], "cd")))
		ft_exec_cd(full);
	else if (!(ft_strcmp(full[0], "unset")))
		ft_unset(full);
	else if (!(ft_strcmp(full[0], "export")))
		ft_export(full);
	else if (!(ft_strcmp(full[0], "exit")))
		ft_exit(full);
	else if ((pid = fork()) == 0)
	{
		if ((ft_check_builtin(full)))
			ft_nobuiltin(full);
		exit(g_code);
	}
	else if (pid < 0)
	{
		printf("Unable to fork\n");
		return ;
	}
	ft_exec4(&pid);
}

void	ft_handler(t_exec *exe, t_list **cmd)
{
	ft_full_init(exe, cmd);
	if (exe->y > 0 && (exe->y % 2 == 0))
		ft_do1(exe, cmd, &exe->flag);
	else if (exe->y > 0 && (exe->y % 2 == 1))
		ft_do2(exe, cmd, &exe->flag, exe->how);
	else if (exe->y == 0 && exe->flag == 1)
		ft_do3(exe, cmd, &exe->file);
	else if (exe->y == 0 && exe->flag == 0)
		ft_do4(exe, cmd, &exe->file, exe->how);
	ft_full_free(exe->full);
}

void	ft_exe(t_list *cmd)
{
	t_exec	*exe;

	if (!(exe = malloc(sizeof(t_exec))))
		exit(0);
	exe->how = 0;
	while (cmd->ag != 999)
	{
		ft_init(exe, cmd, &exe->flag);
		if (exe->y < 2)
			exe->how = 1;
		while (ft_strcmp(cmd->cntent, ";"))
		{
			if (cmd->ag == 1 || cmd->ag == 5 ||
			cmd->ag == 2 || cmd->ag == 3)
				cmd = cmd->next;
			ft_handler(exe, &cmd);
		}
		if (cmd->next)
			cmd = cmd->next;
	}
	free(exe);
}
