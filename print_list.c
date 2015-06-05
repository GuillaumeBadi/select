/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 01:36:25 by sjulliot          #+#    #+#             */
/*   Updated: 2015/06/05 05:03:17 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>

static char		*get_last_name(char *complete_name)
{
	char		*tmp;
	int			len;

	len = ft_strlen(complete_name);
	tmp = complete_name + len;
	while (len--)
	{
		if (complete_name[len] == '/' && len != 0 && complete_name[len - 1] != '\\')
			return (complete_name + len + 1);
	}
	return (complete_name);
}

#include "term/fterm.h"
#include <curses.h>
#include <term.h>

void			enable_rvideo(void)
{
	if (tputs(tgetstr("mr", NULL), 1, ft_outc) == ERR)
		exit(42);
}

void			disale_rvideo(void)
{
	if (tputs(tgetstr("me", NULL), 1, ft_outc) == ERR)
		exit(42);
}

int				print_file_name(t_file *file)
{
	char		*tmp_name;

	if (file->visible % 2 == 0)
		return (0);
	tmp_name = get_last_name(file->name);
	if (file->checked % 2)
		enable_rvideo();
	write(1, tmp_name, ft_min(23, ft_strlen(tmp_name)));
	disale_rvideo();
	return (1);
}

void			enable_underline(void)
{
	if (tputs(tgetstr("us", NULL), 1, ft_outc) == ERR)
		exit(42);
}

void			disable_underline(void)
{
	if (tputs(tgetstr("ue", NULL), 1, ft_outc) == ERR)
		exit(42);
}

void			print_list(t_env *env)
{
	int			index;
	t_chain		*current;

	term_clear(TC_ALL);
	term_goto(0,0);
	index = 0;
	current = env->chain;
	while (current != env->chain || index == 0)
	{
		if (index == env->current_index)
			enable_underline();
		else
			disable_underline();
		index += print_file_name(current->content);
		term_goto(25 * (index / term_height()), (index) % term_height());
		current = current->next;
	}
}
