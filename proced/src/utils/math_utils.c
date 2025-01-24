/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:37:08 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/20 14:38:07 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proced.h>

float	pr_f_clamp(float num, float min, float max)
{
	if (num < min)
		return (num + max);
	if (num > max)
		return (num - max);
	return (num);
}