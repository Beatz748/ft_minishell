#include "minishell.h"

void	ft_error(int i, char **full)
{
	write(1, "\033[1;31m", 8);
	if (i == 1)
		write(1, " Unable to fork =( ", 20);
	if (i == 228)
		write(1, "unable features", 16);
	if (i == 2)
	{
		ft_putstr_fd("pizza-shell: command not found: ", 1);
		ft_putstr_fd(full[0], 1);
	}
	write(1, "\033[0m \n", 7);
}
