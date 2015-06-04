
# include				<libft.h>
# include				<termcap.h>
# include				<unistd.h>
# include				<term.h>
# include				<stdlib.h>
# include				<curses.h>

#include "fterm.h"

void			term_goto(int x, int y)
{
	char		*ap;

	ap = NULL;
	tputs(tgoto(tgetstr("cm", &ap), x, y), 1, ft_outc);
	free(ap);
}
