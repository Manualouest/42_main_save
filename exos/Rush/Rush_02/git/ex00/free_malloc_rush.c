/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_malloc_rush.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:53:12 by glaurich          #+#    #+#             */
/*   Updated: 2023/09/03 16:53:13 by glaurich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	maloc_free_dico(char **dico, int size_dict)
{
	int	i;

	if (dico != NULL)
	{
		i = 0;
		while (i < size_dict)
		{
			if(dico[i] != NULL)
				free(dico[i]);
			i++;
		}
		free(dico);
	}
}
