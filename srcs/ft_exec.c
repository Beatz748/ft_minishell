/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:09:11 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/06 01:25:22 by kshantel         ###   ########.fr       */
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
		auf[i] = (*cmd)->content;
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

	pid = 0;
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
		exit(code);
	}
	else if (pid < 0)
	{
		printf("Unable to fork\n");
		return ;
	}
	waitpid(pid, &status, 0);
	code = WEXITSTATUS(status);
}

void	ft_exe(t_list *cmd)
{
	int		flag;
	int		file;
	t_exec	*exe;
	int		how;

	if (!(exe = malloc(sizeof(t_exec))))
		exit(0);
		how = 0;
	while (cmd->argument != 999)
	{
		ft_init(exe, cmd, &flag);
			if (exe->y < 2)
				how = 1;
		while (ft_strcmp(cmd->content, ";"))
		{
			if (cmd->argument == 1 || cmd->argument == 5 ||
			cmd->argument == 2 || cmd->argument == 3)
				cmd = cmd->next;
			ft_full_init(exe, &cmd);
			if (exe->y > 0 && (exe->y % 2 == 0))
				ft_do1(exe, &cmd, &flag);
			else if (exe->y > 0 && (exe->y % 2 == 1))
				ft_do2(exe, &cmd, &flag, how);
			else if (exe->y == 0 && flag == 1)
				ft_do3(exe, &cmd, &file);
			else if (exe->y == 0 && flag == 0)
				ft_do4(exe, &cmd, &file, how);
			ft_full_free(exe->full);
		}
		if (cmd->next)
			cmd = cmd->next;
	}
}
