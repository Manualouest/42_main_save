/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:45:04 by locharve          #+#    #+#             */
/*   Updated: 2023/08/26 19:58:30 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_var_repeated(int *tab, int var, int i)
{
	if (i < 0)
		return (-1);
	if (var == tab[i])
		return (i);
	else
		return (is_var_repeated(tab, var, i - 1));
}

int	*init_var(int *var, int size) // appelee dans main ?
{
	int	i;

	var = malloc(size * sizeof(int));
	while (i < size)
	{
		var[i] = 1;
		i++;
	}
	return (var);
}

int	*put_case(int **tab, int *var, int *i, int *j, int size) // NORME !!
{
	int	is_same;

	while (*j < size)
	{
		is_same = is_var_repeated(var, var[*j], *j - 1);
		if (var[*j] < 4)
		{
			while (is_same >= 0)
			{
				var[*j]++;
				is_same = is_var_repeated(var, var[*j], *j - 1);
			}
			tab[*i][*j] = var[*j];
		}
		else
		{
			var[*j] = 1;
			*j = is_same - 1;
		}
		*j = *j + 1;
	}
	return (NULL);//(check_line(params, tab, tab[i], size)); NULL si pas de pb.
}

void	try_line(int **tab, int **params, int size)
{
	int	*var;
	int	*ptr;
	int	i;
	int	j;
	int	k;

	var = init_var(var, size); // taille variable ? malloc
	i = 0;
	k = 0;
	while (i < size)
	{
		j = k;
		ptr = put_case(tab, var, &i, &j, size);
		if (ptr == NULL)
			i++;
		else
		{
			k = j;
			//go_backward(ptr, tab, &i, &k); // a coder ; va la ou il y a un pb
		}
	}
	return ;
}
