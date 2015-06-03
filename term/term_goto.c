
#include "term.h"

void			term_goto(int x, int y)
{
	char		*ap;

	ap = NULL;
	tputs(tgoto(tgetstr("cm", &ap), x, y), 1, ft_outc);
	free(ap);
}
