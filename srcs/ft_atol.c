/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:13:22 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/28 17:09:57 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

long	ft_atol(const char *str)
{
	long int	i;
	long		val;
	long		res;

	i = 0;
	val = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			val = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * val);
}
