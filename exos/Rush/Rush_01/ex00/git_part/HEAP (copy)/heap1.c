/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:42:31 by locharve          #+#    #+#             */
/*   Updated: 2023/08/27 14:02:50 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		**init_permut(int size, int facto);
void	copy_int_tab(int *tab1, int *tab2, int size);
void	ft_swap(int *a, int *b);
void	switch_swap(int *suite, int *compteur, int i);
int		**heap_algo(int *suite, int *compteur, int size, int facto);

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}

int	*init_suite(int size)
{
	int	*suite;
	int	i;

	suite = (int *)malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		suite[i] = i + 1;
		i++;
	}
	return (suite);
}

int	*init_compteur(int size)
{
	int	i;
	int	*compteur;

	compteur = (int *)malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		compteur[i] = 0;
		i++;
	}
	return (compteur);
}

int	**all_permutations_tab(int size, int facto)
{
	int	*suite;
	int	**permut;
	int	*compteur;

	compteur = init_compteur(size);
	suite = init_suite(size);
	permut = heap_algo(suite, compteur, size, facto);
	free(compteur);
	free(suite);
	return (permut);
}
/*
int	main(int argc, char **argv)
{
	int	**permut;
	int	i;
	int	j;
	int	size;
	int	facto;

	(void) argc;

	if (argc == 2)
	{
		size = atoi(argv[1]);
		facto = ft_recursive_factorial(size);
		permut = (all_permutations_tab(size, facto));
		i = 0;
		j = 0;
		while (i < facto)
		{
			j = 0;
			while (j < size)
			{
				printf("%d ", permut[i][j]);
				j++;
			}
			free(permut[i]);
			printf("\n");
			i++;
		}
		free(permut);
	}
	return (0);
}
*/
