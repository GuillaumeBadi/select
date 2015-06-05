/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 16:47:57 by sjulliot          #+#    #+#             */
/*   Updated: 2015/06/05 18:02:07 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <curses.h>
#include <strings.h>
#include <ft_mem.h>

extern t_env		g_e;

static char			*get_char(char *buf)
{
	ft_bzero(buf, BUFFSIZE + 1);
	read(0, buf, BUFFSIZE);
	if (buf[0] == 4)
		throw_error("");
	if (buf[0] == 3)
		throw_error("");
	return (buf);
}

static int			print_complet_file_name(t_file *file)
{
	if (file->visible % 2 == 0 || file->checked % 2 == 0)
		return (0);
	ft_putstr(file->name);
	return (1);
}

static void			resize(int i)
{
	char			str[2];

	(void)i;
	str[0] = -62;
	str[1] = '\0';
	ioctl(0, TIOCGWINSZ, str);
	print_list(&g_e);
}

void				end_session(t_env *env)
{
	int				index;
	int				i;
	int				ret;
	t_chain			*current;

	index = 0;
	i = 0;
	current = env->chain->next;
	while (i < env->chain_size && index < env->chain_size - env->deleted - 1
				&& (index == 0 || current != env->chain))
	{
		ret = print_complet_file_name(current->content);
		if (ret && i + 1 < env->chain_size &&
				index + 1 < env->chain_size - env->deleted - 1)
			ft_putstr(" ");
		index += ret;
		i++;
		current = current->next;
	}
	print_complet_file_name(current->content);
}

int					main(int ac, char **av)
{
	char			buf[BUFFSIZE + 1];

	if (ac == 1)
		return (0);
	if (!term_init())
		return (INIT_FAIL);
	g_e.chain = get_list(ac - 1, av + 1);
	g_e.chain_size = ac - 1;
	g_e.current_index = 0;
	g_e.deleted = 0;
	close(0);
	open("/dev/tty", O_RDWR);
	ft_putstr_fd("\033[?1049h\033[H", 0);
	signal(SIGWINCH, resize);
	print_list(&g_e);
	while (handle_input(&g_e, get_char(buf)))
		print_list(&g_e);
	if (term_exit())
		return (EXIT_FAIL);
	ft_putstr_fd("\033[?1049l", 0);
	end_session(&g_e);
	return (2);
}
