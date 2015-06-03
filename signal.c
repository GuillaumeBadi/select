
#include "ft_select.h"

extern int		g_signal;

static int		catch_signal(int sig)
{
	printf("%d\n", sig);
}

void			signal_init(void)
{
	if (signal(SIGINT, catch_signal) == SIG_ERR)
	{
		ft_putendl("Error while setting signal handler");
		exit(42);
	}
}
