/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:36:44 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/10 17:54:00 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_eat_limit(t_philo *philo)
{
	int		id;
	t_data	*data;

	id = 0;
	data = philo->data;
	if (data->initvals.repeats == -1)
		return (0);
	pthread_mutex_lock(&data->mutex.eat_flag);
	while (id < data->initvals.nbr)
	{
		if (philo[id].eat_limit == 0)
			break ;
		id++;
	}
	if (id == data->initvals.nbr)
	{
		pthread_mutex_lock(&data->mutex.dead_flag);
		data->dead = 1;
		pthread_mutex_unlock(&data->mutex.dead_flag);
		pthread_mutex_unlock(&data->mutex.eat_flag);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex.eat_flag);
	return (0);
}

int	ft_death(t_data *data)
{
	int	dead_flag;

	pthread_mutex_lock(&data->mutex.dead_flag);
	dead_flag = data->dead;
	pthread_mutex_unlock(&data->mutex.dead_flag);
	return (dead_flag);
}

int	time_of_death(t_philo *philo)
{
	int		id;
	t_data	*data;

	id = 0;
	data = philo->data;
	while (id < data->initvals.nbr)
	{
		pthread_mutex_lock(&data->mutex.eat_flag);
		if (ft_get_time() - philo[id].last_eaten > data->initvals.time_die)
		{
			pthread_mutex_lock(&data->mutex.dead_flag);
			data->dead = 1;
			data->id_dead = id + 1;
			pthread_mutex_unlock(&data->mutex.dead_flag);
			pthread_mutex_unlock(&data->mutex.eat_flag);
			return (1);
		}
		pthread_mutex_unlock(&data->mutex.eat_flag);
		id++;
	}
	return (0);
}

void	mutex_print(char *str, t_philo *philo)
{
	long	time;

	if (ft_death(philo->data))
		return ;
	pthread_mutex_lock(&philo->data->mutex.write_flag);
	time = ft_get_time() - philo->data->start_time;
	printf("%ld %ld %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->mutex.write_flag);
}

void	ft_sleep(t_data *data, int time)
{
	long	start_sleep;

	start_sleep = ft_get_time();
	while (ft_get_time() - start_sleep < time)
	{
		if (ft_death(data))
			break ;
		usleep(500);
	}
}
