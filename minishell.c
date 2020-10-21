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

void	ft_do_cd(char **full)
{
	chdir(full[1]);
}

void	ft_exec_command(char **full)
{
	if (!(ft_strcmp(full[0], "cd")))
		chdir(full[1]);
	else
		execve("/bin/pwd", full, NULL);
}

void	ft_exec(char **full)
{
	pid_t	pid, wpid;
	int		status;


	pid = fork();
	char *args[] = {"ls", 0};
	if (pid == 0)
		ft_exec_command(full);
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
