#include "minishell.h"
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;37m"
#include <stdio.h>
int		main(int ac, char **av, char **env)
{
	int	i;

	if (!(g_env = env))
		exit(-1);
	write(1, "\033[0;31mpizza-shell ", 20);
	write(1, "BY TBEEDRIL && KSHANTEL 🍕 \033[0m \n\n\n", 38);
	ft_minishell();
}
