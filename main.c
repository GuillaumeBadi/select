/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 19:00:49 by gbadi             #+#    #+#             */
/*   Updated: 2015/06/04 01:54:02 by sjulliot         ###   ########.fr       */
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

void				handle_input(void *e, char *input)
{
	(void)e;
	(void)input;
}

int					main(int ac, char **av)
{
	t_env			e;

	if (ac == 1)
		return (0);
	if (!term_init())
		return (INIT_FAIL);

//	term_loop(&e);
	term_clear(TC_ALL);
	e.chain = get_list(ac - 1, av + 1);
	print_list(&e);
	//printf("term_height [%d]\n", term_height());
	if (term_exit())
		return (EXIT_FAIL);
	return (0);
}
