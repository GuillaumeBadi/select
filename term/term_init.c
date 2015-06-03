
#include "term.h"

int					term_init(void)
{
	char			*term_name;
	struct termios	term;

	if ((term_name = getenv("TERM")) == NULL)
		return (0);
	if (tgetent(NULL, term_name) == ERR)
		return (0);
	if (tcgetattr(0, &term) == -1)
		return (0);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (0);	
	return (1);
}

