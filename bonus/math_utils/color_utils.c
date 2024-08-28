/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:38:54 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/28 11:23:05 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	cd_get_hex(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

float	cd_basic_f_clamp(float num, float min, float max)
{
	if (num < min && num + max <= max)
		return (num + max);
	if (num > max && num - max >= min)
		return (num - max);
	if (num >= min && num <= max)
		return (num);
	while (num < min || num > max)
	{
		if (num < min)
			num = num + max;
		else
			num = num - max;
	}
	return (num);
}

float	cd_f_abs(float num)
{
	if (num < 0)
		return (num * -1.0);
	return (num);
}

float	cd_get_dist(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

float	cd_round(float num, float round)
{
	return (floor(num * round) / round);
}
