#include "minishell.h"

void	ft_signals(int sig)
{
	if (sig == SIGINT)
	{
		exit(-1);
	}
}
