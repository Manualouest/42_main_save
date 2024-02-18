/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 02:12:20 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/18 09:41:38 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

int	sl_is_in_circle(t_map_info map_info, int rad, int ex, int ey)
{
	int			px;
	int			py;

	px = map_info.gifs->xy.x;
	py = map_info.gifs->xy.y;
	if (((ey - rad <= py && ey + rad >= py) && (ex - (rad / 2) <= px
				&& ex + (rad / 2) >= px)) || ((ey - (rad / 2) <= py
				&& ey + (rad / 2) >= py) && (ex - rad <= px && ex + rad >= px))
		|| ((ey - (rad - 1) <= py && ey + (rad - 1) >= py)
			&& (ex - ((rad / 2) + 1) <= px && ex + ((rad / 2) + 1) >= px))
		|| ((ey - ((rad / 2) + 1) <= py && ey + ((rad / 2) + 1) >= py)
			&& (ex - (rad - 1) <= px && ex + (rad - 1) >= px)))
		return (1);
	return (0);
}

int	ft_lstsize(t_img_stack *lst)
{
	int			i;
	t_img_stack	*curr;

	if (lst == NULL)
		return (0);
	i = 1;
	curr = lst;
	while (curr->next != NULL)
	{
		i ++;
		curr = curr->next;
	}
	return (i);
}

int	sl_base_change(int nbr, char *base)
{
	int		tt;

	tt = 0;
	if (nbr < 5)
		tt = base[nbr] - '0';
	else if (nbr >= 5)
	{
		tt += sl_base_change(nbr / 5, base);
		tt = (tt * 10) + (base[nbr % 5] - '0');
	}
	return (tt);
}

int	sl_power(int i, int p)
{
	int	res;

	res = i;
	while (p > 1)
	{
		res *= i;
		p --;
	}
	return (res);
}
