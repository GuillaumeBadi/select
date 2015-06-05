/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 16:49:37 by sjulliot          #+#    #+#             */
/*   Updated: 2015/06/05 16:54:28 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <termcap.h>
#include <unistd.h>
#include <term.h>
#include <stdlib.h>
#include <curses.h>

int			term_width(void)
{
	tgetent(0, getenv("TERM"));
	return (tgetnum("co"));
}

int			term_height(void)
{
	tgetent(0, getenv("TERM"));
	return (tgetnum("li"));
}
