/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:17:47 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/11/11 14:50:35 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*work_mem;

	if (nmemb == 0 || size == 0)
	{
		work_mem = malloc(0);
		if (!work_mem)
			return (0);
		return (work_mem);
	}
	if (nmemb > 2147483647 || size > 2147483647 || nmemb * size > 2147483647)
		return (0);
	work_mem = malloc(nmemb * size);
	if (!work_mem)
		return (0);
	ft_bzero(work_mem, nmemb * size);
	return (work_mem);
}
