/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:49:18 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/08 05:57:34 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_builtin(char **full)
{
	if (!(ft_strcmp(full[0], "pwd")))
		return (ft_exec_pwd(full));
	else if (!(ft_strcmp(full[0], "env")))
		return (ft_printf_env());
	else if (!(ft_strcmp(full[0], "export")))
		return (ft_export(full));
	else if (!(ft_strcmp(full[0], "unset")))
		return (ft_unset(full));
	else if (!(ft_strcmp(full[0], "echo")))
		return (ft_echo(full));
	else if (!(ft_strcmp(full[0], "exit")))
		return (ft_exit(full));
	return (1);
}

void	ft_nobuiltin(char **full)
{
	char	*my_path;

	my_path = NULL;
	if ((my_path = ft_true_path(full)) == NULL)
	{
		ft_minishell2(full);
		return ;
	}
	if (execve(my_path, full, en) == -1)
	{
		ft_error(2, full);
		exit(code);
	}
	free(my_path);
}

void	ft_some_dups(char **full, int pipe_in, int pipe_out)
{
	dup2(pipe_in, STDIN_FILENO);
	dup2(pipe_out, STDOUT_FILENO);
	if ((ft_check_builtin(full)))
		ft_nobuiltin(full);
}

void	ft_exec(char **full, int pipe_in, int pipe_out)
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
	else if ((code = (pid = fork())) == 0)
	{
		ft_some_dups(full, pipe_in, pipe_out);
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

void	ft_minishell(void)
{
	int		i;
	char	*cmd;
	char	dir[MAX_DIR];

	i = 0;
	while (1)
	{
		init_signals(ft_parent_signal);
		write(1, "\033[0;36m Σ>―(〃°ω°〃)♡→ \033[0;35m", 43);
		write(1, getcwd(dir, MAX_DIR), ft_strlen(getcwd(dir, MAX_DIR)));
		write(1, ">\033[0m ", 7);
		if (get_next_line(0, &cmd) == 0)
		// cmd = "echo \"1\"2 \\$PATH";
			exit(code);
		init_signals(ft_child_signal);
		ft_parse(cmd);
		// getchar();
		free(cmd);
	}
}
