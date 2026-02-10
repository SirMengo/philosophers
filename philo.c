/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:03:51 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/10 14:58:47 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_all(t_data *data)
{
	int	id;

	id = 0;
	while (id < data->initvals.nbr)
	{
		pthread_join(data->philo[id].thread, NULL);
		pthread_mutex_destroy(&data->mutex.fork[id]);
		id++;
	}
	pthread_mutex_destroy(&data->mutex.write_flag);
	pthread_mutex_destroy(&data->mutex.dead_flag);
	pthread_mutex_destroy(&data->mutex.eat_flag);
	free(data->philo);
	free(data->mutex.fork);
}

void	monitor(t_philo *philo)
{
	while (1)
	{
		if (check_eat_limit(philo))
			break ;
		if (time_of_death(philo))
			break ;
		usleep(100);
	}
}

void	philo_manager(t_philo *philo)
{
	int	id;
	int	num;

	id = 0;
	while (id < philo->data->initvals.nbr)
	{
		pthread_create(&philo[id].thread, NULL, &routine, &philo[id]);
		id++;
	}
	monitor(philo);
	num = philo->data->id_dead;
	if (philo->data->id_dead > 0)
	{
		pthread_mutex_lock(&philo->data->mutex.write_flag);
		printf("%ld %i died\n",
			ft_get_time() - philo[num - 1].data->start_time, num);
		pthread_mutex_unlock(&philo->data->mutex.write_flag);
	}
	clean_all(philo->data);
}

int	main(int ac, char **av)
{
	static t_data	data;

	if (ac >= 5 && ac <= 6)
	{
		if (init_all(&data, av))
			return (1);
		philo_manager(data.philo);
	}
	else
	{
		write(2, "Error: Invalid number of arguments\n", 35);
		return (1);
	}
}
