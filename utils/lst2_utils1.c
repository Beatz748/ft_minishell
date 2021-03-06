/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:55:25 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/08 07:34:52 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list2		*ft_lenv(void *content, void *name)
{
	t_list2	*new;

	new = (t_list2 *)malloc(sizeof(t_list2));
	if (new == NULL)
		return (NULL);
	new->cntent = content;
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

void		ft_ladd_prev(t_list2 **lst, t_list2 *new)
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
