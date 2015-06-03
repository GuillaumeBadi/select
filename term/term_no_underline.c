
#include "term.h"

void			term_no_underline(void)
{
	char		*buffer;

	buffer = NULL;
	tputs(tgetstr("se", &buffer), 1, ft_outc);
	free(buffer);
}
