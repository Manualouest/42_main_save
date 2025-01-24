/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:25:10 by mhaouas           #+#    #+#             */
/*   Updated: 2024/05/02 18:24:36 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_free_2d_array(void *array, size_t size)
{
	void	**args;
	size_t	i;

	args = array;
	i = 0;
	if (!args)
		return ;
	while (i < size)
		free(args[i++]);
	free(args);
	args = NULL;
}
