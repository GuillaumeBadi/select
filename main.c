/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 19:00:49 by gbadi             #+#    #+#             */
/*   Updated: 2015/05/28 19:01:04 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

struct termios		*start_termios(void)
{
	struct termios	tios;
	struct termios	*orig_tios;    /* terminal settings */

	orig_tios = (struct termios *)malloc(sizeof(struct termios));
	/* Get current terminal settings */
	if (tcgetattr(0, orig_tios)){
		ft_putendl("Error getting current terminal settingsn");
		return (NULL);
	}

	/* Copy that to "tios" and play with it */
	tios = *orig_tios;
	tios.c_lflag &= ~ICANON;
	tios.c_lflag |= ECHO;
	if (tcsetattr(0, TCSANOW, &tios)){
		ft_putendl("Error applying terminal settingsn");
		return (NULL);
	}
	/* Check whether our settings were correctly applied */
	if (tcgetattr(0, &tios)){
		tcsetattr(0, TCSANOW, orig_tios);
		ft_putendl("Error while asserting terminal settingsn");
		return (NULL);
	}
	if ((tios.c_lflag & ICANON) || !(tios.c_lflag & ECHO)) {
		tcsetattr(0, TCSANOW, orig_tios);
		ft_putendl("Could not apply all terminal settingsn");
		return (NULL);
	}
	return (orig_tios);
}

void				end_termios(struct termios *orig_tios)
{
	tcsetattr(0, TCSANOW, orig_tios);
	free(orig_tios);
}

int					main(int ac, char **av)
{
	struct termios	*term_conf_save;

	(void)ac;
	(void)av;
	term_conf_save = start_termios();
	end_termios(term_conf_save);
	return (0);
}
