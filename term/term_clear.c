
#include "term.h"

void				term_clear(char *mode)
{
	char			*buffer;

	buffer = NULL;
	tputs(tgetstr(mode, &buffer), 1, ft_outc);
	free(buffer);
}
