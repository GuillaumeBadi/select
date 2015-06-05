/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 16:49:37 by sjulliot          #+#    #+#             */
/*   Updated: 2015/06/05 16:58:02 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <termcap.h>
#include <unistd.h>
#include <term.h>
#include <stdlib.h>
#include <curses.h>
#include "fterm.h"

void			term_set_cursor(char *mode)
{
	char			*buffer;

	buffer = NULL;
	tputs(tgetstr(mode, &buffer), 0, ft_outc);
	free(buffer);
}
