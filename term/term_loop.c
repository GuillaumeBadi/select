
#include <unistd.h>
#include "fterm.h"

void			term_loop(void *e)
{
	char		buffer[2];
	int			ret;

	while ((ret = read(0, buffer, 2)) > 0)
	{
//		if (4 == buffer[0])
//			return ;
		handle_input(e, buffer);
	}
}
