/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 23:58:13 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/20 02:06:25 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include <dirent.h>
# include <signal.h>
# include <errno.h>

# define ECHO_CMD "echo"
# define EXIT_CMD "exit"
# define CD_CMD "cd"
# define PWD_CMD "pwd"
# define ENV_CMD "env"
# define EXPORT_CMD "export"
# define UNSET_CMD "unset"

char	**g_env;

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);

int		get_next_line(int fd, char **line);

void	ft_signals(int sig);

int		main(int ac, char **av, char **env);

void	ft_minishell();

#endif
