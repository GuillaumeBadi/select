/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   underline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 12:13:43 by sjulliot          #+#    #+#             */
/*   Updated: 2015/06/05 12:20:00 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <curses.h>
#include <term.h>

void			enable_underline(void)
{
	if (tputs(tgetstr("us", NULL), 0, ft_outc) == ERR)
		exit(42);
}

void			disable_underline(void)
{
	if (tputs(tgetstr("ue", NULL), 0, ft_outc) == ERR)
		exit(42);
}
