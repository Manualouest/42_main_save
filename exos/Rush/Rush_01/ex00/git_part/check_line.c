/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabbe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:46:55 by slabbe            #+#    #+#             */
/*   Updated: 2023/08/27 11:03:42 by slabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	*check_line1(int params1, int *line, int size)
{
	int		*ptr;
	int		max;
	int		i;
	int		nbrv1;

	i = 0;
	nbrv1 = 1;
	max = line[0];
	while (i < size)
	{
		if (max < line[i])
		{
			max = line[i];
			nbrv1++;
			ptr = &line[i];
		}
		i++;
	}
	if (nbrv1 == params1)
		return (NULL);
	else
		return (ptr);
}

int	*check_line2(int params2, int *line, int size)
{
	int		j;
	int		max;
	int		nbrv2;
	int		*ptr;

	j = size - 1;
	max = line[size - 1];
	while (j >= 0)
	{
		if (max < line[j])
		{
			max = line[j];
			nbrv2++;
			ptr = &line[j];
		}
		j--;
	}
	if (nbrv2 == params2)
		return (NULL);
	else
		return (ptr);
}

int	*check_all(int params1, int params2, int *line, int size)
{
	int		*ptr;

	ptr = check_line1(params1, line, size);
	if (ptr != NULL)
		return (ptr);
	ptr = check_line2(params2, line, size);
	return (ptr);
}
