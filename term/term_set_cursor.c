
#include "term.h"

void			term_set_cursor(char *mode)
{
	char			*buffer;

	buffer = NULL;
	tputs(tgetstr(mode, &buffer), 1, ft_outc);
	free(buffer);
}
