/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:16:13 by locharve          #+#    #+#             */
/*   Updated: 2023/08/26 15:51:19 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	try_line(int **, int **, int);

void	print_all(int **tab, int **params, int size)
{
	int	i;
	int	j;

	i = 0;
	printf("  ");
	while (i < size)
	{
		printf("%d ", params[0][i]);
		i++;
	}
	printf("\n");

	i = 0;
	while(i < size)
	{
		printf("%d ", params[2][i]);
		j = 0;
		while (j < size)
		{
			printf("%d ", tab[i][j]);
			j++;
		}
		printf("%d\n", params[3][i]);
		i++;
	}

	printf("  ");
	i = 0;
	while (i < size)
	{
		printf("%d ", params[1][i]);
		i++;
	}
	return ;
}

void	free_all(int **tab, int **params, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(params[i]);
		free(tab[i]);
		i++;
	}
	free(params);
	free(tab);
}

int	main(int argc, char **argv) // argv[1] -> size
{								// [2] = params
	(void) argc;
	int	**tab;
	int **params;
	int	size;
	int	i;
	int	j;
	int	k;

	size = atoi(argv[1]);
	params = malloc(size * sizeof(int *));
	tab = malloc(size * sizeof(int *));

	i = 0;
	while (i < size)
	{
		*params = malloc(size * sizeof(int));
		*tab = malloc(size * sizeof(int));
		i++;
	}

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			params[i][j] = argv[2][k] - 48; // init params
			tab[i][j] = 0;
			j++;
			k += 2;
		}
		i++;
	}
	try_line(tab, params, size);
	print_all(tab, params, size);
	free_all(tab, params, size);
}
