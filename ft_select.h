/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 16:58:09 by gbadi             #+#    #+#             */
/*   Updated: 2015/06/04 01:40:30 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include		<libft.h>
# include		<sys/stat.h>
# include		<signal.h>
# include 		"term/fterm.h"

typedef enum		e_file_type
{
	T_FILE,
	T_BIN,
	T_DIR,
	T_HIDDEN,
	T_UNDEFINED
}					t_file_type;

typedef struct		s_file
{
	int				index;
	t_file_type		file_type;
	char			visible;
	char			*name;
}					t_file;


typedef struct		s_env
{
	t_chain			*chain;
}					t_env;

void				signal_init(void);
void				ft_warning (char *message);
void				throw_error(char *message);
t_file_type			get_file_type(char *name);
t_chain				*get_list(int ac, char **argv);
void				print_list(t_env *env);

#endif
