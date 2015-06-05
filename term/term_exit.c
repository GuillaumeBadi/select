/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 16:49:37 by sjulliot          #+#    #+#             */
/*   Updated: 2015/06/05 16:56:04 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <termcap.h>
#include <unistd.h>
#include <term.h>
#include <stdlib.h>
#include <curses.h>
#include "fterm.h"

int					term_exit(void)
{
	struct termios	term;

	term_set_cursor(C_VISIBLE);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
	return (0);
}
