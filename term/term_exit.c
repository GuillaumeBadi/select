
# include				<libft.h>
# include				<termcap.h>
# include				<unistd.h>
# include				<term.h>
# include				<stdlib.h>
# include				<curses.h>

#include "fterm.h"

int					term_exit(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
	return (0);
}

