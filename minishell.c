#include "minishell.h"
#include <stdio.h>
void	ft_minishell(void)
{
	int 	i;
	char	*cmd;

	i = 1;
	while (1)
	{
		signal(SIGINT, ft_signals);
		signal(SIGQUIT, ft_signals);
		write(1, "\033[0;36m Σ>―(〃°ω°〃)♡→ \033[0;35m", 43);
		write(1, getcwd(NULL, 0), ft_strlen(getcwd(NULL, 0)));
		write(1, ">\033[0m ", 7);
		get_next_line(0, &cmd);
		printf("%s\n", cmd);
		if (cmd[1] == 'c')
			printf("TEST");
	}
}
