/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 23:58:13 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/28 20:11:15 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <signal.h>
# include <errno.h>

# define ECHO_CMD "echo"
# define EXIT_CMD "exit"
# define CD_CMD "cd"
# define PWD_CMD "pwd"
# define ENV_CMD "env"
# define EXPORT_CMD "export"
# define UNSET_CMD "unset"

# define max_dir 1024

typedef struct		s_list
{
	void			*content;
	void			*name;
	struct s_list	*next;
}					t_list;

t_list	*g_env;

void	ft_error(int i);

t_list	*ft_parse_env(char **env);

char	*ft_strchr(const char *s, int c);

t_list		*ft_lstnew(void *content, void *name);

t_list		*ft_lstlast(t_list *lst);

void		ft_lstadd_back(t_list **lst, t_list *new);

int			ft_lstsize(t_list *lst);

t_list		*ft_lst_pevlast(t_list *lst);

void		ft_lstadd_prev_back(t_list **lst, t_list *new);

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strdup(const char *s);

int		get_next_line(int fd, char **line);

char		**ft_split(char const *s, char c);

void	ft_signals(int sig);

int		main(int ac, char **av, char **env);

void	ft_minishell();

#endif
