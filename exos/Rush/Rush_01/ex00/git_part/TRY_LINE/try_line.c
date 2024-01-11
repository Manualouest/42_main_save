/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:00:05 by locharve          #+#    #+#             */
/*   Updated: 2023/08/27 17:33:30 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_recursive_factorial(int nb);
void	copy_int_tab(int *tab1, int *tab2, int size);

int	tab_cmp(int *tab1, int *tab2, size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab1[i] != tab2[i])
			return (1);
		i++;
	}
	return (0);
}

int	put_line(int *line, int **permut, int indice_permut, int size)
{
	int	facto;
	int	i;
	int	j;

	facto = ft_recursive_factorial(size);
	i = 0;
	while (i < facto)
	{
		if (i >= indice_permut && tab_cmp(line, permut[i], size) != 0)
		{
			copy_int_tab(line, permut[i], size);
			return (i);
		}
		i++;
	}
	return (i);
}

int	*check_vertical(int **matrix, int **params, int size)
{
	int	*vertical_line;
	int	*error;
	int	i;
	int	j;

	vertical_line = malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			vertical_line[j] = matrix[i][j];
			j++;
		}
		error = check_all(params[0][i], params[1][i], vertical_line, size);
		if (error != NULL)
		{
			free(vertical_line);
			return (error);
		}
		i++;
	}
	free(vertical_line);
	return (NULL);
}

int	*check_check(int **matrix, int **params, int i_l, int size)
{
	int	*error;
	int	i;

	error = check_all(params[2][i_l], params[3][i_l], matrix[0][i_l], size);
	if (error != NULL)
		return (error);
	error = check_vertical_line(matrix, params, size);
	return (error);
}

void	reset_line(int	*line, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		line[i] = 0;
		i++;
	}
	return ;
}

int	try_line(int **matrix, int **params, int **permut, int size)
{
	int	*error;
	int	i;
	int	indice_permut[4];
	int	facto;

	i = 0;
	indice_permut = 0;
	facto = 
	while (i < size)
	{
		indice_permut = put_line(&matrix[0][i], permut, indice_permut[i], size);
		if (indice_permut[i] >= facto)
		{
			if (i == 0) 
				return (-1);
			else
			{
				indice_permut[i] = 0;
				indice_permut[i - 1]++;
				i--;
				continue ;
			}
		}
		error = check_check(matrix, params, i, size); ////////////
		if (error != NULL)
		{
			indice_permut[i]++;
			reset_line(&matrix[0][i], size);
			continue ;
		}
		i++;
	}
	return (0);
}
