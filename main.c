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

#define INIT_FAIL 1
#define EXIT_FAIL 2

void				handle_input(t_env *e, char *input)
{
	(void)e;
	(void)input;
	printf("%s\n", input);
}

int					main(int ac, char **av)
{
	t_env			e;

	(void)ac;
	(void)av;
	if (!term_init())
		return (INIT_FAIL);

	printf("%d\n", term_width());

	if (term_exit())
		return (EXIT_FAIL);
	return (0);
}
