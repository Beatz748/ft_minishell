/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:07:37 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/29 20:10:37 by kshantel         ###   ########.fr       */
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

t_list		*ft_lstnew(void *content, void *name)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->name = name;
	new->next = NULL;
	return (new);
}

t_list		*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	new->next = last->next;
	last->next = new;
}

t_list		*ft_lst_prevlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}

void		ft_lstadd_prev_back(t_list **lst, t_list *new)
{
	t_list	*last;

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

int			ft_lstsize(t_list *lst)
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


t_list	*ft_parse_env(char **env)
{
	t_list	*my_env = NULL;
	int i;
	char *p;

	i = 0;
	p = NULL;
	while (env[i])
	{
		p = ft_strchr(env[i], '=');
		*p = '\0';
		ft_lstadd_back(&my_env, ft_lstnew(++p, env[i]));
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
