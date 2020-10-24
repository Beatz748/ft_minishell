#include "minishell.h"
#include <stdio.h>


int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t ft_strlen2(char **full)
{
	char **s;
	size_t len;

	s = full;
	len = 0;
	while (*s != NULL)
	{
		s++;
		len++;
	}
	return (len);
}

void	ft_do_cd(char **full)
{
	chdir(full[1]);
}

void	ft_printf_env(void)
{
	t_list *tmp;

	tmp = g_env;
	while (tmp)
	{
		printf("%s=%s\n", tmp->name, tmp->content);
		tmp = tmp->next;
	}
}

void	ft_unset(char **full)
{
	int i;
	t_list *tmp, *srch;

	i = 1;
	while (full[i])
	{
		if (!(ft_strcmp(full[i], "_")))
			i++;
		else
		{
			tmp = g_env;
			while (tmp && ft_strcmp(tmp->next->name, full[i]) != 0)
				tmp = tmp->next;
			if (tmp)
			{
				srch = tmp->next;
				tmp->next = srch->next;
				free(srch);
			}
			i++;
		}
	}
}

void	ft_export(char **full)
{
	char *p_e;
	t_list *tmp;
	int i;

	i = 1;
	while (full[i])
	{
		p_e = NULL;
		tmp = g_env;
		if (!(p_e = ft_strchr(full[i], '=')))
			p_e = "";
		else
		{
			*p_e = '\0';
			p_e++;
		}
		while (tmp && ft_strcmp(tmp->name, full[i]) != 0)
			tmp = tmp->next;
		if (!tmp)
			ft_lstadd_prev_back(&g_env, ft_lstnew(p_e, full[i]));
		else
		{
			tmp->content = p_e;
		}
		i++;
	}
}

void	ft_our_commands(char **full)
{
	if (!(ft_strcmp(full[0], "cd")))
	{
		if (ft_strlen2(full) > 2)
			printf("cd: too many arguments\n");
		else if (chdir(full[1]) == -1)
			printf("cd: no such file or directory: %s\n", full[1]);
	}
	else if (!(ft_strcmp(full[0], "pwd")))
	{
		write(1, getcwd(NULL, 0), ft_strlen(getcwd(NULL, 0)));
		write(1, "\n", 1);
	}
	else if(!(ft_strcmp(full[0], "env")))
		ft_printf_env();
	else if (!(ft_strcmp(full[0], "export")))
		ft_export(full);
	else if (!(ft_strcmp(full[0], "unset")))
		ft_unset(full);
	else
		printf("minishell: command not found\n");
}

void	ft_exec(char **full)
{
	pid_t	pid, wpid;
	int		status;

	pid = fork();
	if (pid == 0)
		ft_our_commands(full);
	else if (pid < 0)
		ft_error(1);
	wait(&pid);
}

void	ft_minishell(void)
{
	int 	i;
	char	*cmd;
	char	**full;

	i = 1;
	while (1)
	{
		signal(SIGINT, ft_signals);
		signal(SIGQUIT, ft_signals);
		write(1, "\033[0;36m Σ>―(〃°ω°〃)♡→ \033[0;35m", 43);
		write(1, getcwd(NULL, 0), ft_strlen(getcwd(NULL, 0)));
		write(1, ">\033[0m ", 7);
		get_next_line(0, &cmd);
		full = ft_split(cmd, ' ');
		ft_exec(full);
	}
}
