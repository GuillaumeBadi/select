/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fterm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjulliot <sjulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 16:50:24 by sjulliot          #+#    #+#             */
/*   Updated: 2015/06/05 16:50:55 by sjulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTERM_H

# define FTERM_H

# define TC_ALL			"cl"
# define TC_FROM_CURSOR	"cd"
# define TC_LINE 		"ce"

# define C_VISIBLE		"ve"
# define C_INVISIBLE	"vi"

int						ft_outc(int c);
void					term_clear(char *mode);
int						term_init(void);
int						term_exit(void);
void					term_goto(int x, int y);
void					term_underline(void);
void					term_no_underline(void);
int						term_height(void);
int						term_width(void);
void					term_set_cursor(char *mode);
void					term_loop(void *e);

#endif
