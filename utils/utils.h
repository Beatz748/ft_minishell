/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:31:37 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/07 00:14:22 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_list
{
	char			*content;
	int				argument;
	int				merge;
	struct s_list	*next;
}					t_list;

typedef struct		s_list2
{
	void			*content;
	void			*name;
	struct s_list2	*next;
}					t_list2;

int					ft_strcmp(char *s1, char *s2);
size_t				ft_strlen2(char **full);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
int					ft_atoi(const char *str);
char				*ft_strchr(const char *s, int c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strfjoin(char *s1, char *s2);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_len(t_list *cmd);
int					ft_list_pipes(t_list *cmd);
void				ft_full_free(char **my_path);
char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);
int					get_next_line(int fd, char **line);
void				ft_list_clear(t_list **begin_list);
t_list				*ft_lstnew(void *content, int flag, int merge);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list2				*ft_lstnew_env(void *content, void *name);
t_list2				*ft_lstlast_env(t_list2 *lst);
void				ft_lstadd_back_env(t_list2 **lst, t_list2 *new);
t_list2				*ft_lst_prevlast(t_list2 *lst);
void				ft_lstadd_prev_back(t_list2 **lst, t_list2 *new);
int					ft_lstsize_env(t_list2 *lst);
char				*ft_itoa(int n);

#endif
