/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rvideo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 12:10:56 by sjulliot          #+#    #+#             */
/*   Updated: 2015/06/05 12:20:24 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <curses.h>
#include <term.h>

void			enable_rvideo(void)
{
	if (tputs(tgetstr("mr", NULL), 0, ft_outc) == ERR)
		exit(42);
}

void			disale_rvideo(void)
{
	if (tputs(tgetstr("me", NULL), 0, ft_outc) == ERR)
		exit(42);
}
