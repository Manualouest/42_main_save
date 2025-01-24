/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrech <malbrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:57:07 by mhaouas           #+#    #+#             */
/*   Updated: 2024/05/14 16:56:04 by malbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_array_len(void *array)
{
	void	**args;
	size_t	i;

	args = array;
	i = 0;
	if (!args || !*args)
		return (0);
	while (args[i])
		i++;
	return (i);
}
