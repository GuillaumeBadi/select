
#include "term.h"

int			term_width(void)
{
	return (tgetnum("co"));
}

int 		term_height(void)
{
	return (tgetnum("li"));
}
