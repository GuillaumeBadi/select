/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 01:36:25 by sjulliot          #+#    #+#             */
/*   Updated: 2015/06/04 02:58:09 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>

static char		*get_last_name(char *complete_name)
{
	char		*tmp;
	size_t		len;

	len = ft_strlen(complete_name);
	tmp = complete_name + len;
	while (len--)
	{
		if (complete_name[len] == '/' && len != 0 && complete_name[len - 1] != '\\')
			return (complete_name + len + 1);
	}
	return (complete_name);
}

void			print_list(t_env *env)
{
	int			index;
	t_chain		*current;
	char		*tmp_name;

	term_goto(0,0);
	index = 0;
	current = env->chain;
	while (current != env->chain || index == 0)
	{
		tmp_name = get_last_name(((t_file*)(current->content))->name);
		write(1, tmp_name, ft_min(47, ft_strlen(tmp_name)));
//		term_goto(0, index + 1);
		term_goto(50 * (index / term_height()), (index) % term_height());
		index += 1;
		current = current->next;
	}
}
