/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:18:18 by msimoes           #+#    #+#             */
/*   Updated: 2025/09/05 13:43:16 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parser (char **args, t_philo *philo, int flag)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (ft_isdigit(args[i]) == 0 || is_positive(ft_atol(args[i])) == 0)
		{
			write(2, "Error: Invalid argument\n", 24);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	philo->nbr = ft_atol(args[1]);
	philo->forks = ft_atol(args[1]);
	philo->time_die = ft_atol(args[2]);
	philo->time_eat = ft_atol(args[3]);
	philo->time_sleep = ft_atol(args[4]);
	if (flag == 1)
		philo->repeats = ft_atol(args[5]);
}
