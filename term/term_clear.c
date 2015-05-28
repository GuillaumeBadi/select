/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 19:18:21 by gbadi             #+#    #+#             */
/*   Updated: 2015/05/28 19:41:38 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <term.h>
#include <stdio.h>


/*
static int				ft_outc(int c)
{
	ft_putchar(c);
	return (0);
}
*/

int				term_clear(void)
{
	char		*res;

	res = tgetstr("cl", NULL);
	if (!res)
		return (-1);
	tputs(res, 0, &ft_putchar);
	return (0);
}
