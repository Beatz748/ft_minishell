/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <tbeedril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:31:18 by tbeedril          #+#    #+#             */
/*   Updated: 2020/11/25 18:51:07 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strfjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	j = 0;
	while (j < i && s1[j] != '\0')
	{
		str[j] = s1[j];
		j++;
	}
	k = 0;
	while (j < i && s2[k] != '\0')
	{
		str[j] = s2[k];
		j++;
		k++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	y;
	size_t	i;
	char	*str;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[y])
		str[i++] = s2[y++];
	str[i] = '\0';
	return (str);
}

int		ft_len(t_list *cmd)
{
	int		i;

	i = 0;
	while (cmd->argument == 0 ||
	cmd->argument == 2 || cmd->argument == 1)
	{
		i++;
		cmd = cmd->next;
	}
	return (i);
}

int		ft_list_pipes(t_list *cmd)
{
	int		i;

	i = 0;
	while (cmd)
	{
		if (cmd->argument == 5 &&
		(ft_strcmp(cmd->content, ";")))
			i++;
		cmd = cmd->next;
	}
	return (i);
}

void	ft_full_free(char **my_path)
{
	int		i;

	i = 0;
	while (my_path[i])
		free(my_path[i++]);
	free(my_path);
}
