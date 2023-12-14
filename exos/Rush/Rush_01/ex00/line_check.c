/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:33:31 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/27 11:33:33 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//all_permutations_tab
int	**make_table(int len)
{
	int	pos;
	int	pos2;
	int	**matrix;

	pos = 0;
	pos2 = 0;
	matrix = malloc(len * sizeof(int *));
	while (pos < len)
	{
		matrix[pos] = malloc(len * sizeof(int));
		while (pos2 < len)
		{
			matrix[pos][pos2] = 0;
			pos2 ++;
		}
		pos2 = 0;
		pos ++;
	}
	return (matrix);
}

void	printer(int **tab, int size)
{
	int	pos;
	int	pos2;
	int	temp;

	pos = 0;
	while (pos < size)
	{
		pos2 = 0;
		while (pos2 < size)
		{
			temp = tab[pos][pos2] + '0';
			write (1, &temp, 1);
			write (1, " ", 1);
			pos2 ++;
		}
		write (1, "\n", 1);
		pos ++;
	}
}

int	main(void)
{
	int	**test_matrix;
	int	pos;
	int	pos2;

	pos = 0;
	pos2 = 0;
	test_matrix = make_table(4);
	printer (test_matrix, 4);
	pos = 0;
	while (pos < 4)
	{
		free(test_matrix[pos]);
		pos ++;
	}
	free(test_matrix);
}
