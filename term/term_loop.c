
#include "term.h"

void			term_loop(void *e)
{
	char		buffer[2];
	int			ret;

	while ((ret = read(0, buffer, 2)) > 0)
	{
		if (*buffer == 4)
		{
			handle_input(e, buffer);
			return ;
		}
	}
}
