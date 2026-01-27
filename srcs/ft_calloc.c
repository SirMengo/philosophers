/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:19:12 by msimoes           #+#    #+#             */
/*   Updated: 2026/01/27 13:52:13 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

static void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	size_t	mult;

	if (n == 0 || size == 0)
		return (malloc(0));
	mult = n * size;
	if (n > INT_MAX / size)
		return (NULL);
	ptr = malloc(mult);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, mult);
	return (ptr);
}
