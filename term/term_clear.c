
#include "term.h"

void				term_clear(void)
{
	char			*buffer;

	buffer = NULL;
	tputs(tgetstr("cl", &buffer), 1, ft_outc);
	free(buffer);
}
