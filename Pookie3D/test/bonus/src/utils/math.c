/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:28:17 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 12:28:18 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

float	cd_clamp(float num, float min, float max)
{
	while (num < min)
		num += max;
	while (num > max)
		num -= max;
	return (num);
}

float	cd_clamp_two(float num, float min, float max)
{
	if (num < min)
		return (min);
	if (num > max)
		return (max);
	return (num);
}
