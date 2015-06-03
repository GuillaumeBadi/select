
#include "term.h"

void			term_underline(void)
{
	char		*buffer;

	buffer = NULL;
	tputs(tgetstr("so", &buffer), 1, ft_outc);
	free(buffer);
}
