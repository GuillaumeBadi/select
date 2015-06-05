/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 19:00:49 by gbadi             #+#    #+#             */
/*   Updated: 2015/06/05 05:44:30 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <curses.h>
#include <strings.h>
#include <ft_mem.h>

#define INIT_FAIL 1
#define EXIT_FAIL 2

#define BUFFSIZE	3

#define K_ESC		"\e\0\0"
#define K_TOP		"\e[A"
#define K_BOTTOM	"\e[B"
#define K_RIGHT		"\e[C"
#define K_LEFT		"\e[D"
#define K_S			"s\0\0"
#define K_X			"x\0\0"

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

int					handle_input(t_env *e, char *input)
{
	if (ft_strncmp(input, K_ESC, BUFFSIZE) == 0)
		return (0);
	if (ft_strncmp(input, K_X, BUFFSIZE) == 0)
	{
		((t_file*)(ft_chnat_file(e->chain, e->current_index)->content))->visible++;
		e->deleted++;
		if (e->deleted == e->chain_size)
			return (0);
	}
	if (ft_strncmp(input, K_TOP, BUFFSIZE) == 0)
		e->current_index--;
	if (ft_strncmp(input, K_BOTTOM, BUFFSIZE) == 0)
		e->current_index++;
	if (ft_strncmp(input, K_RIGHT, BUFFSIZE) == 0)
	{
		if (e->current_index / term_height() == (e->chain_size - e->deleted) / term_height())
			e->current_index %= term_height();
		else if (e->current_index / term_height() == (e->chain_size - e->deleted) / term_height() - 1 && e->current_index % term_height() >= (e->chain_size - e->deleted) % term_height())
			e->current_index = e->chain_size - e->deleted - 1;
		else
			e->current_index += term_height();
	}
	if (ft_strncmp(input, K_LEFT, BUFFSIZE) == 0)
	{
		if (e->current_index / term_height() == 0 && (e->current_index - e->deleted) % term_height() >= (e->chain_size - e->deleted) % term_height())
			e->current_index = e->chain_size - e->deleted - 1;
		else if (e->current_index / term_height() == 0)
			e->current_index = ((e->chain_size - e->deleted) / term_height()) * term_height() + e->current_index % term_height();
		else
			e->current_index -= term_height();
	}
	if (e->current_index < 0 || e->current_index > e->chain_size - e->deleted - 1)
		e->current_index = (e->current_index + e->chain_size - e->deleted) % (e->chain_size - e->deleted) ;
	if (ft_strncmp(input, K_S, BUFFSIZE) == 0)
		((t_file*)(ft_chnat_file(e->chain, e->current_index)->content))->checked++;
	return (1);
}

char				*get_char(char *buf)
{
	ft_bzero(buf, BUFFSIZE + 1);
	read(0, buf, BUFFSIZE);
	return (buf);
}


int					print_complet_file_name(t_file *file)
{
	if (file->visible % 2 == 0 || file->checked % 2 == 0)
		return (0);
	ft_putstr(file->name);
	return (1);
}

void				end_session(t_env *env)
{
	int				index;
	int				ret;
	t_chain			*current;

	index = 0;
	current = env->chain;
	while (index < env->chain_size - env->deleted - 1 && (index == 0 || current != env->chain))
	{
		ret = print_complet_file_name(current->content);
		if (ret)
			ft_putstr(" ");
		index += ret;
		current = current->next;
	}
	print_complet_file_name(current->content);
}

int					main(int ac, char **av)
{
	t_env			e;
	char			buf[BUFFSIZE + 1];

	if (ac == 1)
		return (0);
	if (!term_init())
		return (INIT_FAIL);
	e.chain = get_list(ac - 1, av + 1);
	e.chain_size = ac - 1;
	e.current_index = 0;
	e.deleted = 0;
	term_clear(TC_ALL);
	print_list(&e);
	while (handle_input(&e, get_char(buf)))
		print_list(&e);
	if (term_exit())
		return (EXIT_FAIL);
	end_session(&e);
	return (0);
}
