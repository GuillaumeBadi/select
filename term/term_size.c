
# include				<libft.h>
# include				<termcap.h>
# include				<unistd.h>
# include				<term.h>
# include				<stdlib.h>
# include				<curses.h>

#include "fterm.h"

int			term_width(void)
{
	return (tgetnum("co"));
}

int 		term_height(void)
{
	return (tgetnum("li"));
}

int			column_nb(int items_nb)
{
	return (items_nb / term_height() + 1);
}
