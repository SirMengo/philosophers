/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:18:18 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/26 14:51:45 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parser(char **args, t_initvals *initvals, int flag)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (ft_isdigit(args[i]) == 0 || is_positive(ft_atol(args[i])) == 0)
		{
			write(2, "Error: Invalid argument\n", 24);
			return (1);
		}
		i++;
	}
	initvals->nbr = ft_atol(args[1]);
	initvals->forks = ft_atol(args[1]);
	initvals->time_die = ft_atol(args[2]);
	initvals->time_eat = ft_atol(args[3]);
	initvals->time_sleep = ft_atol(args[4]);
	if (flag == 1)
		initvals->repeats = ft_atol(args[5]);
	else
		initvals->repeats = -1;
	return (0);
}
