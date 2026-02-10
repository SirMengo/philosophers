/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:25:50 by msimoes           #+#    #+#             */
/*   Updated: 2026/02/10 17:51:13 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	parser(char **args, t_initvals *initvals)
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
	initvals->time_die = ft_atol(args[2]);
	initvals->time_eat = ft_atol(args[3]);
	initvals->time_sleep = ft_atol(args[4]);
	if (args[5])
	{
		initvals->repeats = ft_atol(args[5]);
		if (initvals->repeats == 0)
			return (1);
	}
	else
		initvals->repeats = -1;
	return (0);
}

static void	init_philo(t_philo *table, int id, t_data *data)
{
	table->data = data;
	table->id = id + 1;
	table->times_eaten = 0;
	table->last_eaten = ft_get_time();
	table->eat_limit = 0;
	table->fork_left = &data->mutex.fork[id];
	table->fork_right = &data->mutex.fork[(id + 1) % data->initvals.nbr];
}

static t_philo	*init_table(t_data *data)
{
	int		id;
	t_philo	*table;

	table = ft_calloc(data->initvals.nbr, sizeof(t_philo));
	if (!table)
		return (NULL);
	id = 0;
	while (id < data->initvals.nbr)
	{
		init_philo(&table[id], id, data);
		id++;
	}
	if (id == data->initvals.nbr)
		data->check = 1;
	return (table);
}

static int	init_mutex(t_data *data)
{
	int	i;

	data->mutex.fork = ft_calloc(data->initvals.nbr, sizeof(pthread_mutex_t));
	if (!data->mutex.fork)
		return (1);
	i = 0;
	while (i < data->initvals.nbr)
	{
		if (pthread_mutex_init(&data->mutex.fork[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->mutex.fork[i]);
			return (1);
		}
		i++;
	}
	pthread_mutex_init(&data->mutex.write_flag, NULL);
	pthread_mutex_init(&data->mutex.dead_flag, NULL);
	pthread_mutex_init(&data->mutex.eat_flag, NULL);
	return (0);
}

int	init_all(t_data *data, char **args)
{
	t_initvals	initvals;

	if (parser(args, &initvals))
		return (1);
	if (ft_atol(args[1]) == 1)
	{
		printf("0 1 has taken a fork\n");
		usleep(ft_atol(args[2]) * 1000);
		printf("%ld 1 died\n", ft_atol(args[2]));
		return (1);
	}
	data->initvals = initvals;
	init_mutex(data);
	data->check = 0;
	data->dead = 0;
	data->id_dead = 0;
	data->start_time = ft_get_time();
	data->philo = init_table(data);
	if (!data->philo)
		return (write(2, "Error: Initializing table\n", 26), 1);
	return (0);
}
