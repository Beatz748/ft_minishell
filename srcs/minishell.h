/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 23:58:13 by kshantel          #+#    #+#             */
/*   Updated: 2020/12/08 16:31:54 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../utils/utils.h"
# include "../parser/parse.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>
# include <fcntl.h>
# define BUFFER_SIZE 32
# define MAX_DIR 1024

typedef struct	s_exec
{
	char		**full;
	int			pipefd[2];
	int			pipefd2[2];
	int			y;
	int			size_mini;
	int			how;
	int			flag;
	int			file;
}				t_exec;
char			**g_en;
t_list2			*g_env;
int				g_code;

int				ft_do_cd(char **full);
int				ft_exec_cd(char **full);
int				ft_exec_pwd(char **full);
int				ft_echo(char **full);
int				ft_printf_env(void);
void			ft_exec4(pid_t *pid);
char			**ft_path(void);
char			*ft_true_path(char **full);
int				ft_exit(char **full);
int				ft_export(char **full);
int				ft_unset(char **full);
void			ft_error(int i, char **full);
void			ft_error2(int i);
void			ft_init(t_exec *exe, t_list *cmd, int *flag);
int				ft_full_init(t_exec *exe, t_list **cmd);
void			ft_exe(t_list *cmd);
void			ft_signals(int sig);
void			ft_do1(t_exec *exe, t_list **cmd, int *flag);
void			ft_do2(t_exec *exe, t_list **cmd, int *flag, int how);
void			ft_do3(t_exec *exe, t_list **cmd, int *file);
void			ft_do4(t_exec *exe, t_list **cmd, int *file, int how);
int				ft_check_builtin(char **full);
void			ft_nobuiltin(char **full);
void			ft_exec(char **full, int pipe_in, int pipe_out);
void			ft_minishell(void);
int				ft_new_fd(t_list **cmd);
void			ft_minishell2(char **full);
void			ft_child_signal(int sig);
void			ft_parent_signal(int sig);
void			init_signals(void (*func)(int));

#endif
