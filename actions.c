/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:04:56 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/28 16:04:29 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	forks(t_philo *philo)
{
	if ((philo->id % 2) == 0)
	{
		pthread_mutex_lock(philo->fork_left);
		mutex_print("has taken a fork", philo);
		pthread_mutex_lock(philo->fork_right);
		mutex_print("has taken a fork", philo);
	}
	else
	{
		pthread_mutex_lock(philo->fork_right);
		mutex_print("has taken a fork", philo);
		pthread_mutex_lock(philo->fork_left);
		mutex_print("has taken a fork", philo);
	}
}

static void	action_eat(t_philo *philo)
{
	forks(philo);
	pthread_mutex_lock(&philo->data->mutex.eat_flag);
	mutex_print("is eating", philo);
	philo->times_eaten = philo->times_eaten + 1;
	philo->last_eaten = ft_get_time();
	if (philo->eat_limit == philo->data->initvals.repeats)
		philo->eat_limit = 1;
	pthread_mutex_unlock(&philo->data->mutex.eat_flag);
	ft_sleep(philo->data, philo->data->initvals.time_eat);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

static void	action_sleep(t_philo *philo)
{
	mutex_print("is sleeping", philo);
	ft_sleep(philo->data, philo->data->initvals.time_sleep);
}

static void	action_think(t_philo *philo)
{
	mutex_print("is thinking", philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if ((philo->id % 2) == 0)
		ft_sleep(data, 10);
	while (ft_death(data) == 0)
	{
		action_eat(philo);
		action_sleep(philo);
		action_think(philo);
	}
	return (NULL);
}
