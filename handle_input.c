/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 12:00:06 by sjulliot          #+#    #+#             */
/*   Updated: 2015/06/05 16:32:24 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <ft_chn.h>

t_chain				*ft_chnat_file(t_chain *chn, int pos)
{
	while (pos || ((t_file*)(chn->content))->visible % 2 == 0)
	{
		if (((t_file*)(chn->content))->visible % 2 == 1)
			pos--;
		chn = chn->next;
	}
	return (chn);
}

static int			is_del(char *buf)
{
	if ((buf[0] == 27 && buf[1] == 91 && buf[2] == 51)
		|| (buf[0] == 127 && buf[1] == 0 && buf[2] == 0))
		return (1);
	return (0);
}

static int			is_enter(char *buf)
{
	return ((buf[0] == 10 && buf[1] == 0 && buf[2] == 0));
}

int					handle_input(t_env *e, char *input)
{
	if (ft_strncmp(input, K_ESC, BUFFSIZE) == 0)
		input_exit();
	else if (is_enter(input))
		return (0);
	else if (is_del(input) && !input_del(e))
		return (0);
	else if (ft_strncmp(input, K_TOP, BUFFSIZE) == 0)
		e->current_index--;
	else if (ft_strncmp(input, K_BOTTOM, BUFFSIZE) == 0)
		e->current_index++;
	else if (ft_strncmp(input, K_RIGHT, BUFFSIZE) == 0)
		input_right(e);
	else if (ft_strncmp(input, K_LEFT, BUFFSIZE) == 0)
		input_left(e);
	else if (ft_strncmp(input, K_SPACE, BUFFSIZE) == 0)
		input_space(e);
	if (e->current_index < 0
			|| e->current_index > e->chain_size - e->deleted - 1)
		e->current_index = (e->current_index + e->chain_size - e->deleted)
							% (e->chain_size - e->deleted);
	return (1);
}
