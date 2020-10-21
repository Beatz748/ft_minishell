#include "minishell.h"

void	ft_error(int i)
{
	write(1, "\033[1;31m", 8);
	if (i == 1)
		write(1, " Unable to fork =( ", 20);
	if (i == 228)
		write(1, "unable features", 16);
	write(1, "\033[0m \n\n", 8);
}
