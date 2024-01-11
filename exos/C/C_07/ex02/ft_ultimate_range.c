/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:00:19 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/28 20:00:21 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*a;
	int	b;
	int	pos;

	pos = 0;
	b = max - min;
	if (max <= min)
	{
		*range = 0;
		return (0);
	}
	if (b < 0)
		b = b * -1;
	a = malloc(b * sizeof(int));
	while (pos < max - min)
	{
		a[pos] = min + pos;
		pos ++;
	}
	*range = a;
	return (max - min);
}
