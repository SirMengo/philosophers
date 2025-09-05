/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:03:51 by msimoes           #+#    #+#             */
/*   Updated: 2025/09/05 13:39:50 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	static t_philo philo;

	if (argc >= 6 && argc <= 7)
	{
		if (argc == 7)
			parser(argv, &philo, 1);
		else
			parser(argv, &philo, 0);
	}
	else
	{
		write(2, "Error: Invalid number of arguments\n", 35);
		exit(EXIT_FAILURE);
	}
}