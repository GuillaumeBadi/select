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
#include "ft_select.h"

void			throw_error(char *message)
{
	ft_putendl(message);
	term_exit();
	exit(42);
}
