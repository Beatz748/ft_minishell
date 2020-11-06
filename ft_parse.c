#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"
// typedef struct		s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }					t_list;

void	ft_list_clear(t_list **begin_list)
{
	if (*begin_list != NULL)
	{
		ft_list_clear(&((*begin_list)->next));
		free(*begin_list);
		*begin_list = NULL;
	}
}

char	*ft_strndup(const char *s, size_t n)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = malloc(sizeof(char) * (n + 1));
	if (res == NULL)
		return (NULL);
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

t_list		*ft_lstnew(void *content, int flag)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->argument = flag;
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

void	ft_new_1quo(char **new, t_list **tmp, int *res)
{
	char	*str;
	int		wordlen;

	wordlen = 0;
	*res += 1;
	*new += 1;
	while (**new && **new != '\'')
	{
		*new += 1;
		wordlen += 1;
	}
	str = ft_strndup(*new - wordlen, wordlen);
	ft_lstadd_back(tmp, ft_lstnew(str, 0));
	if (**new)
		*new += 1;
	if (*new)
		*res += words_get(new, tmp);
}

void	ft_new_word(char **new, t_list **tmp, int *res)
{
	char	*str;
	int		wordlen;

	*res += 1;
	wordlen = 0;
	while (**new != ' ' && **new && **new != ';' && **new != '\'' && **new != '\"' && **new != '$' && **new != '>' && **new != '<' && **new != '|')
	{
		*new += 1;
		wordlen += 1;
	}
	str = ft_strndup(*new - wordlen, wordlen);
	ft_lstadd_back(tmp, ft_lstnew(str, 0));
	if (*new)
		*res += words_get(new, tmp);
}

void	ft_new_2quo(char **new, t_list **tmp, int *res)
{
	char	*str;
	int		wordlen;

	*res += 1;
	*new += 1;
	wordlen = 0;
	while (**new && **new != '\"')
	{
		*new += 1;
		wordlen += 1;
	}
	str = ft_strndup(*new - wordlen, wordlen);
	ft_lstadd_back(tmp, ft_lstnew(str, 0));
	if (++*new)
		*res += words_get(new, tmp);
}

void	ft_do_space(char **new, t_list **tmp, int *res)
{
	while (**new == ' ' && **new && **new != ';' && **new != '\'' && **new != '\"' && **new != '$' && **new != '>' && **new != '<' && **new != '|')
		*new += 1;
	if (*new)
		*res += words_get(new, tmp);
}

void	ft_sign_dollar(char **new, t_list **tmp, int *res)
{
	char	*str;
	int		wordlen;

	*res += 1;
	*new += 1;
	wordlen = 1;
	while (**new != ' ' && **new && **new != ';' && **new != '\'' && **new != '\"' && **new != '$' && **new != '>' && **new != '<' && **new != '|')
	{
		*new += 1;
		wordlen += 1;
	}
	str = ft_strndup(*new - wordlen, wordlen);
	ft_lstadd_back(tmp, ft_lstnew(str, 0));
	if (++*new)
		*res += words_get(new, tmp);
}

void	ft_signs(char **new, t_list **tmp, int *res)
{
	if (**new == '<')
		ft_lstadd_back(tmp, ft_lstnew("<", 1));
	if (**new == '>')
		ft_lstadd_back(tmp, ft_lstnew(">", 1));
	if (**new == ';')
		ft_lstadd_back(tmp, ft_lstnew(";", 1));
	if (**new == '|')
		ft_lstadd_back(tmp, ft_lstnew("|", 1));
	*res += 1;
	*new += 1;
	if (**new)
		*res += words_get(new, tmp);
}

int words_get(char **s, t_list **tmp)
{
	int res;
	char *new;

	res = 0;
	if (!*s || **s == '\0' || !(new = *s))
		return (0);
	if (*new == '\'')
		ft_new_1quo(&new, tmp, &res);
	else if (*new == '\"')
		ft_new_2quo(&new, tmp, &res);
	else if (*new != ' ' && *new != ';' && *new != '$' && *new != '>' && *new != '<' && *new != '|')
		ft_new_word(&new, tmp, &res);
	else if (*new == ' ')
		ft_do_space(&new, tmp, &res);
	else if (*new == ';' || *new == '<' || *new == '>' || *new == '|')
		ft_signs(&new, tmp, &res);
	else if (*new == '$')
		ft_sign_dollar(&new, tmp, &res);
	return (res);
}

char	**ft_parse(char *line)
{
	t_list	*tmp;
	int		size;
	char	**full;
	int		i;
	tmp = NULL;
	size = words_get(&line, &tmp);
	i = 0;

	if (!(full = malloc(sizeof(char **) * size + 1)))
		return (NULL);
	t_list *temp = tmp;
	while(i < size && tmp )
	{
		if (tmp->argument == 1)
		{
			full[i] = NULL;
			ft_exec(full);
			full = full + i;
			size -= i;
			i = -1;
		}
		else
			full[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	full[i] = NULL;
	// ft_exec(full);
	ft_list_clear(&temp);
	return (full);
}
