/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:42:10 by locharve          #+#    #+#             */
/*   Updated: 2023/08/27 14:01:16 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**init_permut(int size, int facto)
{
	int	**permut;
	int	i;

	permut = (int **)malloc(facto * sizeof(int *));
	i = 0;
	while (i < facto)
	{
		permut[i] = (int *)malloc(size * sizeof(int));
		i++;
	}
	return (permut);
}

void	copy_int_tab(int *permut, int *suite, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		permut[i] = suite[i];
		i++;
	}
	return ;
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	switch_swap(int *suite, int *compteur, int i)
{
	if (i % 2 == 0)
		ft_swap(&suite[0], &suite[i]);
	else
		ft_swap(&suite[compteur[i]], &suite[i]);
	return ;
}

int	**heap_algo(int *suite, int *compteur, int size, int facto)
{
	int	**permut;
	int	i;
	int	j;

	permut = init_permut(size, facto);
	copy_int_tab(permut[0], suite, size);
	i = 0;
	j = 1;
	while (i < size && j < facto)
	{
		if (compteur[i] < i)
		{
			switch_swap(suite, compteur, i);
			copy_int_tab(permut[j], suite, size);
			j++;
			compteur[i]++;
			i = 0;
		}
		else
		{
			compteur[i] = 0;
			i++;
		}
	}
	return (permut);
}
