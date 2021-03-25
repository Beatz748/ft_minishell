/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <tbeedril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:49:18 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/12 21:37:58 by tbeedril         ###   ########.fr       */
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
	if (execve(my_path, full, g_en) == -1)
	{
		ft_error(2, full);
		exit(g_code);
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

void	ft_exec4(pid_t *pid)
{
	int	status;

	waitpid(*pid, &status, 0);
	g_code = WEXITSTATUS(status);
}

void	ft_exec(char **full, int pipe_in, int pipe_out)
{
	pid_t	pid;

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
		ft_some_dups(full, pipe_in, pipe_out);
		exit(g_code);
	}
	else if (pid < 0)
	{
		ft_printf("Unable to fork\n");
		return ;
	}
	ft_exec4(&pid);
}
