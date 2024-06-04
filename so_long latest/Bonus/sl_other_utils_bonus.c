/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_other_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:49:38 by mbirou            #+#    #+#             */
/*   Updated: 2024/03/28 21:13:47 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

void	ft_putnbr(int n)
{
	unsigned int	temp;
	char			num;

	if (n < 0)
	{
		write(1, "-", 1);
		temp = n * -1;
	}
	else
		temp = n;
	if (temp > 9)
		ft_putnbr(temp / 10);
	num = temp % 10 + '0';
	write(1, &num, 1);
}

void	sl_update_c_num(t_map_info *map_info)
{
	int	i;
	int	ii;

	i = -1;
	map_info->c_num = 0;
	while (++i < map_info->size.y)
	{
		ii = -1;
		while (++ii < map_info->size.x)
		{
			if (map_info->map[i][ii] == 'C')
				map_info->c_num ++;
		}
	}
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
