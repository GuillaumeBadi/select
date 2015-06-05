/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 16:58:09 by gbadi             #+#    #+#             */
/*   Updated: 2015/06/05 17:50:52 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <sys/stat.h>
# include <signal.h>
# include "term/fterm.h"
# include <libft.h>
# include <termcap.h>
# include <fcntl.h>
# include <unistd.h>
# include <term.h>
# include <stdlib.h>
# include <curses.h>

# define INIT_FAIL		1
# define EXIT_FAIL		2

# define BUFFSIZE		8

# define K_ESC			"\e\0\0"
# define K_TOP			"\e[A"
# define K_BOTTOM		"\e[B"
# define K_RIGHT		"\e[C"
# define K_LEFT			"\e[D"
# define K_S			"s\0\0"
# define K_X			"x\0\0"
# define K_SPACE		" \0\0"
# define K_ENTER		"\10\0\0"

# define C_RED		"\x1b[31m"
# define C_RESET	"\x1b[0m"

typedef enum		e_file_type
{
	T_FILE,
	T_BIN,
	T_DIR,
	T_HIDDEN,
	T_UNDEFINED
}					t_file_type;

typedef struct		s_file
{
	int				index;
	t_file_type		file_type;
	char			visible;
	char			checked;
	char			*name;
}					t_file;

typedef struct		s_env
{
	t_chain			*chain;
	int				chain_size;
	int				current_index;
	int				deleted;
	struct termios	term;
	int				fd;
}					t_env;

t_env				g_e;

void				ft_warning (char *message);
void				throw_error(char *message);
int					handle_input(t_env *env, char *str);
t_file_type			get_file_type(char *name);
t_chain				*get_list(int ac, char **argv);
void				print_list(t_env *env);
void				enable_rvideo(void);
void				disale_rvideo(void);
void				enable_underline(void);
void				disable_underline(void);
void				end_session(t_env *env);
void				input_exit(void);
int					input_del(t_env *e);
void				input_left(t_env *e);
void				input_right(t_env *e);
t_chain				*ft_chnat_file(t_chain *chn, int pos);
void				input_space(t_env *e);

#endif
