
# include				<libft.h>
# include				<termcap.h>
# include				<unistd.h>
# include				<term.h>
# include				<stdlib.h>
# include				<curses.h>
#include "fterm.h"

void				term_clear(char *mode)
{
	char			*buffer;

	buffer = NULL;
	tputs(tgetstr(mode, &buffer), 1, ft_outc);
//	ft_putendl("Hello");
//	ft_putstr(buffer);
	free(buffer);
}
