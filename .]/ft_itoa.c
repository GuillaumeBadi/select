/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:20:06 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/14 06:02:32 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_itoa(int number)
{
	int			len;
	char		*result;
	int			i;

	if (number == 0)
		return (ft_strdup("0"));
	if (number == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(number);
	result = (char *)malloc(sizeof(char) * len + 1);
	i = len;
	len--;
	if (number < 0)
	{
		number = -number;
		result[0] = '-';
	}
	while (number > 0)
	{
		result[len] = number % 10 + 48;
		number = number / 10;
		len--;
	}
	result[i] = '\0';
	return (result);
}
