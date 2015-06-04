/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 00:57:27 by sjulliot          #+#    #+#             */
/*   Updated: 2015/06/04 00:58:54 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_io.h>

void			ft_warning (char *message)
{
	ft_putendl(message);
}

void			throw_error(char *message)
{
	ft_putendl(message);
	exit(42);
}
