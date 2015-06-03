
#ifndef TERM_H

# define TERM_H

# include				<termcap.h>
# include				<unistd.h>
# include				<term.h>
# include				<stdlib.h>
# include				<curses.h>

# define ALL			"cl"
# define FROM_CURSOR	"cd"
# define LINE			"ce"

# define VISIBLE		"ve"
# define INVISIBLE		"vi"

int						ft_outc(int c);

void					term_clear(char *mode);
int						term_init(void);
int						term_exit(void);
void					term_goto(int x, int y);
void					term_underline(void);
void					term_no_underline(void);
int 					term_height(void);
int						term_width(void);
void					term_set_cursor(char *mode);

#endif
