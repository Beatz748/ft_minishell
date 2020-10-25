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

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &(s[i]), 1);
		i++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

int		ft_do_cd(char **full)
{
	chdir(full[1]);
	return (0);
}

int		ft_printf_env(void)
{
	t_list *tmp;

	tmp = g_env;
	while (tmp)
	{
		printf("%s=%s\n", tmp->name, tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

int		ft_unset(char **full)
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
	return (0);
}

int		ft_export(char **full)
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
	return (0);
}

int		ft_exec_cd(char **full)
{
	if (ft_strlen2(full) > 2)
		printf("cd: too many arguments\n");
	else if (chdir(full[1]) == -1)
		printf("cd: no such file or directory: %s\n", full[1]);
	return (0);
}

int		ft_exec_pwd(char **full)
{
	write(1, getcwd(NULL, 0), ft_strlen(getcwd(NULL, 0)));
	write(1, "\n", 1);
	return (0);
}

int		ft_exit(char **full)
{
	exit(0);
	return (0);
}

int		ft_echo(char **full)
{
	full++;
	while (*full)
	{
		ft_putstr_fd(*full, 1);
		full++;
	}
	write(1, "\n", 1);
	return (0);
}
int		ft_check_builtin(char **full)
{
	if (!(ft_strcmp(full[0], "cd")))
		return (ft_exec_cd(full));
	else if (!(ft_strcmp(full[0], "pwd")))
		return (ft_exec_pwd(full));
	else if(!(ft_strcmp(full[0], "env")))
		return (ft_printf_env());
	else if (!(ft_strcmp(full[0], "export")))
		return (ft_export(full));
	else if (!(ft_strcmp(full[0], "unset")))
		return (ft_unset(full));
	else if (!(ft_strcmp(full[0], "echo")))
		return (ft_echo(full));
	else if (!(ft_strcmp(full[0], "exit")))
		return (ft_exit(full));
	return (1);
}

char	**ft_path()
{
	t_list	*tmp;
	char	**my_path;

	tmp = g_env;
	while (tmp->next && ((ft_strcmp(tmp->name, "PATH"))))
		tmp = tmp->next;
	if (!(ft_strcmp(tmp->name, "PATH")))
		return (my_path = ft_split(tmp->content, ':'));
	return (NULL);
}

char	*ft_true_path(char **full)
{
	struct stat buf;
	char	**my_path;
	char	*full_path;

	my_path = ft_path();
	while (my_path && ((buf.st_mode & S_IFMT) != S_IFREG))
	{
	full_path = ft_strjoin(*my_path++, "/");
	full_path = ft_strjoin(full_path, full[0]);
	stat(full_path, &buf);
	}
	if ((buf.st_mode & S_IFMT) == S_IFREG)
		return (full_path);
	else if (stat(full[0], &buf))
		return (full[0]);
	return (NULL);
}



void	ft_nobuiltin(char **full)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;
	char	**my_path;

	my_path = ft_path();
	pid = fork();
	if (pid == 0)
		execve(ft_true_path(full), full, NULL);
	else if (pid < 0)
		ft_error(1);
	wait(&pid);
}

void	ft_exec(char **full)
{
	if ((ft_check_builtin(full)))
		ft_nobuiltin(full);
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
