/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 23:58:13 by kshantel          #+#    #+#             */
/*   Updated: 2020/11/06 18:08:05 by kshantel         ###   ########.fr       */
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
# define BUFFER_SIZE 32
# define CD_CMD "cd"
# define PWD_CMD "pwd"
# define ENV_CMD "env"
# define EXPORT_CMD "export"
# define UNSET_CMD "unset"

# define max_dir 1024


typedef struct		s_list2
{
	void			*content;
	void			*name;
	struct s_list2	*next;
}					t_list2;


typedef struct		s_list
{
	void			*content;
	int				argument;
	struct s_list	*next;
}					t_list;

t_list2	*g_env;

void	ft_error(int i, char **full);

t_list2	*ft_parse_env(char **env);

char	*ft_strchr(const char *s, int c);

void	ft_exec(char **full);

t_list2		*ft_lstnew_env(void *content, void *name);

int		get_next_line2(int fd, char **line);

int	ft_strcmp(char *s1, char *s2);

size_t ft_strlen2(char **full);

t_list2		*ft_lstlast_env(t_list2 *lst);

void		ft_lstadd_back_env(t_list2 **lst, t_list2 *new);

int			ft_lstsize_env(t_list2 *lst);

t_list2		*ft_lst_pevlast(t_list2 *lst);

void	ft_putstr_fd(char *s, int fd);

char	*ft_strndup(const char *s, size_t n);

t_list		*ft_lstlast(t_list *lst);

void		ft_lstadd_back(t_list **lst, t_list *new);

int			ft_lstsize(t_list *lst);

void	ft_new_1quo(char **new, t_list **tmp, int *res);

void	ft_new_word(char **new, t_list **tmp, int *res);

void	ft_new_2quo(char **new, t_list **tmp, int *res);

void	ft_do_space(char **new, t_list **tmp, int *res);

void	ft_sign_dollar(char **new, t_list **tmp, int *res);

void	ft_signs(char **new, t_list **tmp, int *res);

int words_get(char **s, t_list **tmp);

char	**ft_parse(char *line);

t_list		*ft_lstnew(void *content, int flag);

void		ft_lstadd_prev_back(t_list2 **lst, t_list2 *new);

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strdup(const char *s);

int		get_next_line(int fd, char **line);

char		**ft_split(char const *s, char c);

void	ft_signals(int sig);

int		main(int ac, char **av, char **env);

void	ft_minishell();

#endif
