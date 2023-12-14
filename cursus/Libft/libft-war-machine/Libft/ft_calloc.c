/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:32:32 by mbirou            #+#    #+#             */
/*   Updated: 2023/10/31 14:58:53 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <strings.h>

static void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	int		i;
	void	*array;

	i = 0;
	if ((nmemb * size > INT_MAX)
		|| (nmemb == 0 || size == 0))
		return (0);
	array = malloc(size * nmemb);
	ft_bzero(array, nmemb * size);
	return (array);
}

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i ++;
	}
}
