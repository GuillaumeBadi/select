/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 16:39:30 by sjulliot          #+#    #+#             */
/*   Updated: 2015/06/05 16:39:32 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			input_exit(void)
{
	if (term_exit())
		exit(55);
	ft_putstr_fd("\033[?1049l", 0);
	exit(0);
}

int				input_del(t_env *e)
{
	((t_file*)(ft_chnat_file(e->chain, e->current_index)->content))->visible++;
	e->deleted++;
	if (e->deleted == e->chain_size)
		return (0);
	return (1);
}

void			input_left(t_env *e)
{
	if (e->current_index / term_height() == 0 && (e->current_index - e->deleted)
				% term_height() >= (e->chain_size - e->deleted) % term_height())
		e->current_index = e->chain_size - e->deleted - 1;
	else if (e->current_index / term_height() == 0)
		e->current_index = ((e->chain_size - e->deleted) / term_height())
				* term_height() + e->current_index % term_height();
	else
		e->current_index -= term_height();
}

void			input_right(t_env *e)
{
	if (e->current_index / term_height() == (e->chain_size - e->deleted)
				/ term_height())
		e->current_index %= term_height();
	else if (e->current_index / term_height() == (e->chain_size - e->deleted)
				/ term_height() - 1 && e->current_index % term_height()
				>= (e->chain_size - e->deleted) % term_height())
		e->current_index = e->chain_size - e->deleted - 1;
	else
		e->current_index += term_height();
}

void			input_space(t_env *e)
{
	((t_file*)(ft_chnat_file(e->chain, e->current_index)->content))->checked++;
	e->current_index++;
}
