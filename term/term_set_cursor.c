
# include				<libft.h>
# include				<termcap.h>
# include				<unistd.h>
# include				<term.h>
# include				<stdlib.h>
# include				<curses.h>

#include "fterm.h"

void			term_set_cursor(char *mode)
{
	char			*buffer;

	buffer = NULL;
	tputs(tgetstr(mode, &buffer), 1, ft_outc);
	free(buffer);
}
