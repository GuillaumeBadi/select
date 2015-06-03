
#ifndef TERM_H

# define TERM_H

# include				<termcap.h>
# include				<unistd.h>
# include				<term.h>
# include				<stdlib.h>
# include				<curses.h>

void					term_clear(void);
int						term_init(void);
int						term_exit(void);
int						ft_outc(int c);
void					term_goto(int x, int y);
void					term_underline(void);
void					term_no_underline(void);
int 					term_height(void);
int						term_width(void);

#endif
