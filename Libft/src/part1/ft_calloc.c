/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:32:32 by mbirou            #+#    #+#             */
/*   Updated: 2024/10/10 18:50:57 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	m_size;

	m_size = nmemb * size;
	if (m_size < 0)
		return (0);
	array = malloc(m_size);
	if (!array)
		return (NULL);
	ft_bzero(array, m_size);
	return (array);
}
