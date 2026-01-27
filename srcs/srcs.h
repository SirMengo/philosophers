/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:30:17 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/27 11:00:44 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRCS_H
# define SRCS_H

# include "../philo.h"

long	ft_atol(const char *str);
void	*ft_calloc(size_t n, size_t size);
long	ft_get_time(void);
int		ft_isdigit(char *c);
int		is_positive(long nbr);

#endif