/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:07:37 by kshantel          #+#    #+#             */
/*   Updated: 2020/11/04 20:49:57 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

t_list2		*ft_lstnew_env(void *content, void *name)
{
	t_list2	*new;

	new = (t_list2 *)malloc(sizeof(t_list2));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->name = name;
	new->next = NULL;
	return (new);
}

t_list2		*ft_lstlast_env(t_list2 *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void		ft_lstadd_back_env(t_list2 **lst, t_list2 *new)
{
	t_list2	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast_env(*lst);
	new->next = last->next;
	last->next = new;
}

t_list2		*ft_lst_prevlast(t_list2 *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}

void		ft_lstadd_prev_back(t_list2 **lst, t_list2 *new)
{
	t_list2	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lst_prevlast(*lst);
	new->next = last->next;
	last->next = new;
}

int			ft_lstsize_env(t_list2 *lst)
{
	int		count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}


t_list2	*ft_parse_env(char **env)
{
	t_list2	*my_env = NULL;
	int i;
	char *p;

	i = 0;
	p = NULL;
	while (env[i])
	{
		p = ft_strchr(env[i], '=');
		*p = '\0';
		ft_lstadd_back_env(&my_env, ft_lstnew_env(++p, env[i]));
	//	printf("%s\n", (char*)my_env->name);
		i++;
	}

	return (my_env);
}

int		main(int ac, char **av, char **env)
{
	g_env = ft_parse_env(env);
	write(1, "\033[0;31mpizza-shell ", 20);
	write(1, "BY TBEEDRIL && KSHANTEL 🍕 \033[0m \n\n\n", 38);
	ft_minishell();
}
