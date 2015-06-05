/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 01:36:25 by sjulliot          #+#    #+#             */
/*   Updated: 2015/06/05 17:56:08 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>
#include "term/fterm.h"
#include <curses.h>
#include <term.h>

static char		*get_last_name(char *complete_name)
{
	char		*tmp;
	int			len;

	len = ft_strlen(complete_name);
	tmp = complete_name + len;
	while (len--)
	{
		if (complete_name[len] == '/' && len != 0
				&& complete_name[len - 1] != '\\')
			return (complete_name + len + 1);
	}
	return (complete_name);
}

static int		print_file_name(t_file *file)
{
	char		*tmp_name;

	if (file->visible % 2 == 0)
		return (0);
	tmp_name = get_last_name(file->name);
	if (file->checked % 2)
		enable_rvideo();
	write(0, tmp_name, ft_min(23, ft_strlen(tmp_name)));
	disale_rvideo();
	return (1);
}

static void		fill_with_x(void)
{
	int			i;
	int			j;

	i = term_height();
	while (i--)
	{
		j = term_width();
		while (j--)
		{
			term_goto(j, i);
			ft_putstr_fd(C_RED, 0);
			write(0, "X", 1);
			ft_putstr_fd(C_RESET, 0);
		}
	}
}

static int		too_small(t_env *env)
{
	int			col_nb;

	col_nb = (env->chain_size + term_height() - 1) / term_height();
	if (term_width() < 25 || col_nb > term_width() / 25)
	{
		fill_with_x();
		return (1);
	}
	return (0);
}

void			print_list(t_env *env)
{
	int			index;
	t_chain		*current;

	term_clear(TC_ALL);
	if (too_small(env))
		return ;
	term_goto(0, 0);
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
