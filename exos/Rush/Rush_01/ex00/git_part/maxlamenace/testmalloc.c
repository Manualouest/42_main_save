/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:01:22 by malbrech          #+#    #+#             */
/*   Updated: 2023/08/27 10:01:24 by malbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	**arg_matrix(char *str, int nbr_arg)
{
	int	i;
	int	j;
	int	k;
	int	**matrix;
	
	matrix = (int **)malloc(nbr_arg * sizeof(int *));
	i = 0;
	k = 0;
	while (i < nbr_arg)
	{
		matrix[i] = (int *)malloc(nbr_arg * sizeof(int));
		j = 0;
		while (j < nbr_arg)
		{
			matrix[i][j] = str[k] - 48;
			j++;
			k++;
		}
		i++;
	}
	//free(str);
	return (matrix);
}

int	main(int ac, char **av)
{
	int	**test;
	int	size;
	int	i;
	int	j;
	
	size = 4 ;
	
	if ( ac == 2)
	{
		test = arg_matrix(av[1], size);
		i = 0;
		while(i < size)
		{
			j = 0;
			while(j < size)
			{
				printf("%d ", test[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
		i = size - 1;
		while (i >= 0)
		{
			free(test[i]);
			i--;
		}
		free(test);
		
	}
}
