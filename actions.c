/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:04:56 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/27 15:54:26 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action_eat(t_philo *philo)
{
	mutex_print("is eating", philo);
}

void	action_sleep(t_philo *philo)
{
	mutex_print("is sleeping", philo);
}

void	action_think(t_philo *philo)
{
	mutex_print("is thinking", philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->id % 2 == 0)
		ft_sleep(data, 10);
	while (1)
	{
		action_eat(philo);
		action_sleep(philo);
		action_think(philo);
	}
	return (NULL);
}
