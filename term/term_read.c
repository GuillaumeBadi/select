/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 20:02:39 by gbadi             #+#    #+#             */
/*   Updated: 2015/05/28 20:24:22 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_select.h"
#include <stdio.h>

int				term_read(t_env *e, void (*fn)(t_env *, char*))
{
	char		buffer[3];

	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 4)
			exit(0);
		fn(e, buffer);
	}
	return (0);
}
