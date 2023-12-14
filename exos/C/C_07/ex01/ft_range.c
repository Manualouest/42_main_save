/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:59:34 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/28 17:59:35 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*a;
	int	b;
	int	pos;

	pos = 0;
	b = max - min;
	if (max <= min)
	{
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
	return (a);
}
