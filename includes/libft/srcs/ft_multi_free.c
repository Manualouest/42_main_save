/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:06:11 by mhaouas           #+#    #+#             */
/*   Updated: 2024/04/05 16:10:40 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_multi_free(int n_to_free, ...)
{
	va_list	va_to_free;
	void	*tmp;
	int		i;

	i = 0;
	va_start(va_to_free, n_to_free);
	while (i < n_to_free)
	{
		tmp = va_arg(va_to_free, void *);
		if (tmp)
			free(tmp);
		i++;
	}
	va_end(va_to_free);
}
