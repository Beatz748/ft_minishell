#include "minishell.h"
#include <stdio.h>

int		ft_do_cd(char **full)
{
	chdir(full[1]);
	return (0);
}

int		ft_printf_env(void)
{
	t_list2 *tmp;

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
	t_list2 *tmp, *srch;

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
	t_list2 *tmp;
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
			ft_lstadd_prev_back(&g_env, ft_lstnew_env(p_e, full[i]));
		else
		{
			tmp->content = p_e;
		}
		i++;
	}
	return (0);
}

char	*ft_get_gome()
{
	t_list2	*tmp;
	char	*home;

	tmp = g_env;
	while (tmp && (ft_strcmp(tmp->name, "HOME")))
		tmp = tmp->next;
	if (tmp)
		home = tmp->content;
	return (home);
}

int		ft_exec_cd(char **full)
{

	if (ft_strlen2(full) > 2)
		printf("cd: too many arguments\n");
	if (!(full[1]))
		chdir(ft_get_gome());
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
	while (*full != NULL)
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
	t_list2	*tm;
	char	**my_pat;

	tm = g_env;
	while (tm->next && ((ft_strcmp(tm->name, "PATH"))))
		tm = tm->next;
	if (!(ft_strcmp(tm->name, "PATH")))
		return (my_pat = ft_split(tm->content, ':'));
	return (NULL);
}

char	*ft_true_path(char **full)
{
	struct stat buf;
	char	**my_path;
	char	*full_path;
	char	*tmp;

	if(!(my_path = ft_path()))
		return (NULL);
	full_path = NULL;
	while (*my_path && ((buf.st_mode & S_IFMT) != S_IFREG))
	{
		if (full_path)
			free(full_path);
		full_path = ft_strjoin(*my_path++, "/");
		tmp = full_path;
		full_path = ft_strjoin(full_path, full[0]);
		free(tmp);
		stat(full_path, &buf);
	}
	if ((buf.st_mode & S_IFMT) == S_IFREG)
		return (full_path);
	free(full_path);
	return (NULL);
}

void	ft_full_free(char **my_path)
{
	int		i;

	i = 0;
	while (my_path[i])
		free(my_path[i++]);
	free(my_path);
}

void	ft_minishell2(char **full)
{
	char	*path;
	char	dir[max_dir];

	path = getcwd(dir, max_dir);
	path = ft_strjoin(path, "/");
	path = ft_strjoin(path, full[0] + 2);
	if (execve(path, full, NULL) == -1)
	{
		ft_error(2, full);
		_exit(42);
	}
}

void	ft_nobuiltin(char **full)
{
	int status;
	char *my_path;
	pid_t pid;

	my_path = NULL;

	pid = fork();
	if (pid == -1)
		printf("Unable to fork\n");
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
	} else {
		if ((my_path = ft_true_path(full)) == NULL)
		{
			ft_minishell2(full);
			return;
		}
		if (execve(my_path, full, NULL) == -1)
		{
			ft_error(2, full);
			_exit(42);
		}
	}
	free(my_path);
}

void	ft_exec(char **full)
{
	if (full[0] == NULL)
		return;
	if ((ft_check_builtin(full)))
		ft_nobuiltin(full);
}

void	ft_checking(char *cmd)
{
	char	**full;
	int		i;

	i = 0;
		full = ft_parse(cmd);
		ft_exec(full);
		i = 0;
		while (full[i])
			free(full[i++]);
		free(full);
}
# include <fcntl.h>
void	ft_minishell(void)
{
	int 	i;
	char	*cmd;
	char	**full;
	int fd;
	char	dir[max_dir];

	i = 0;
	while (1)
	{
		signal(SIGINT, ft_signals);
		signal(SIGQUIT, ft_signals);
		// fd = open("te", O_RDONLY);
		write(1, "\033[0;36m Σ>―(〃°ω°〃)♡→ \033[0;35m", 43);
		write(1, getcwd(dir, max_dir), ft_strlen(getcwd(dir, max_dir)));
		write(1, ">\033[0m ", 7);
		get_next_line(0, &cmd);
		ft_checking(cmd);
		free(cmd);
	}
}
