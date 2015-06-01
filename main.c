/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 19:00:49 by gbadi             #+#    #+#             */
/*   Updated: 2015/05/28 20:34:31 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <curses.h>

struct termios		*start_termios(void)
{
	char			*term_name;
	struct termios	term;
	struct termios	*save;

	save = (struct termios*)malloc(sizeof(struct termios));
	if ((term_name = getenv("TERM")) == NULL)
		return (NULL);
	if (tgetent(NULL, term_name) == ERR)
		return (NULL);
	if (tcgetattr(0, &term) == -1)
		return (NULL);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (NULL);	
	return (save);
}

void				end_termios(struct termios *term_conf_save)
{
	tcsetattr(0, 0, term_conf_save);
	free(term_conf_save);
}

void				handle_input(t_env *e, char *input)
{
	(void)e;
	(void)input;
}

int					main(int ac, char **av)
{
	struct termios	*term_conf_save;
	t_env			e;

	(void)ac;
	(void)av;
	term_conf_save = start_termios();
	term_read(&e, handle_input);
	end_termios(term_conf_save);
	return (0);
}
