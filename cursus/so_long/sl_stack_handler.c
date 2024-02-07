/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_stack_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:35:23 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/07 03:41:27 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include.h"
#include <stdio.h>

char	*sl_wall_finder(t_map_info *map_info, t_x_y coord)
{
	int		x;
	int		y;
	int		xmax;
	int		ymax;
	char	**mp;

	x = coord.x;
	y = coord.y;
	xmax = map_info->size.x - 1;
	ymax = map_info->size.y - 1;
	mp = map_info->map_copy;
	if ((y > 0 && y < ymax && (mp[y - 1][x] / 1 > 0 || mp[y - 1][x] == -11
		|| mp[y - 1][x] == -5 || mp[y - 1][x] == -16 || mp[y - 1][x] == -17))
		&& (x > 0 && mp[y][x - 1] / 1 > 0) && (x < xmax && mp[y][x + 1] != 49)
		&& mp[y + 1][x] == 49)
	{
		map_info->map_copy[y][x] = -11;
		return ("images/wall/11.png");
	}
	if ((y > 0 && (mp[y - 1][x] / 1 > 0 || mp[y - 1][x] == -11
		|| mp[y - 1][x] == -5 || mp[y - 1][x] == -16 || mp[y - 1][x] == -17))
		&& (x > 0 && mp[y][x - 1] / 1 > 0) && (x < xmax && mp[y][x + 1] != 49)
		&& mp[y + 1][x] != 49)
	{
		map_info->map_copy[y][x] = -11;
		return ("images/wall/22.png");
	}
	if (x > 0 && x < xmax && y < ymax && ((mp[y][x - 1] / 1 < 0 
		&& mp[y + 1][x] == 49 && mp[y][x + 1] == 49)))
	{
		map_info->map_copy[y][x] = -5;
		return ("images/wall/5.png");
	}
	if ((x > 0 && x < xmax && y < ymax && y > 0 && ((mp[y][x - 1] == -6
		&& mp[y + 1][x] != 49 && mp[y - 1][x] != -16 && mp[y - 1][x] != -17
		&& mp[y - 1][x] != -5) || (mp[y + 1][x] != 49 && mp[y - 1][x] != 49
		&& ((mp[y][x - 1] / 1 < 0 && mp[y][x + 1] == 49)
		|| ((mp[y][x - 1] / 1 > 0 && mp[y][x + 1] != 49))))))
		|| (y == 0 && mp[y + 1][x] != 49))
	{
		map_info->map_copy[y][x] = -6;
		return ("images/wall/6.png");
	}
	if (y > 0 && x > 0 && x < xmax && y < ymax && (((mp[y - 1][x] == -17
		|| mp[y - 1][x] == -16|| mp[y - 1][x] == -5) && mp[y][x + 1] == 49
		&& mp[y][x - 1] / 1 > 0 && mp[y + 1][x] != 49) || (mp[y - 1][x] / 1 > 0
		&& mp[y][x - 1] / 1 > 0 && mp[y + 1][x] != 49 && mp[y][x + 1] == 49)))
	{
		map_info->map_copy[y][x] = -18;
		return ("images/wall/18.png");
	}
	if (y > 0 && x > 0 && x < xmax && y < ymax && (((mp[y - 1][x] == -16
		|| mp[y - 1][x] == -17 || mp[y - 1][x] == -5) && mp[y][x - 1] / 1 < 0
		&& mp[y][x + 1] != 49 && mp[y + 1][x] != 49) || (mp[y - 1][x] / 1 > 0
		&& mp[y][x - 1] / 1 < 0 && mp[y + 1][x] != 49 && mp[y][x + 1] != 49)))
	{
		map_info->map_copy[y][x] = -19;
		return ("images/wall/19.png");
	}
	if (y > 0 && x > 0 && x < xmax && y < ymax
		&& (((mp[y - 1][x] == -11 || mp[y - 1][x] == -5 || mp[y - 1][x] == -6
		|| mp[y - 1][x] == -17) && mp[y][x - 1] / 1 < 0 && mp[y + 1][x] == 49
		&& (mp[y][x + 1] != 49)) || (mp[y + 1][x] == 49 && mp[y + 1][x] == 49
		&& mp[y][x + 1] != 49)))
	{
		map_info->map_copy[y][x] = -16;
		return ("images/wall/16.png");
	}
	if (y > 0 && x > 0 && x < xmax && y < ymax
		&& (((mp[y - 1][x] == -11 || mp[y - 1][x] == -5 || mp[y - 1][x] == -16)
		&& !(mp[y][x - 1] / 1 < 0) && mp[y][x + 1] == 49 && mp[y + 1][x] == 49)
		|| (mp[y + 1][x] == 49 && mp[y + 1][x] == 49 && mp[y][x - 1] != -17)))
	{
		map_info->map_copy[y][x] = -17;
		return ("images/wall/17.png");
	}
	if (y > 0 && x > 0 && x < xmax && (mp[y - 1][x] == -11
		|| mp[y - 1][x] == -5 || mp[y - 1][x] == -16 || mp[y - 1][x] == -17)
		&& (mp[y][x - 1] == -3 || mp[y][x - 1] == -1 || mp[y][x - 1] == -7
		|| mp[y][x - 1] == -4) && (mp[y][x + 1] == 49))
	{
		map_info->map_copy[y][x] = -4;
		return ("images/wall/4.png");
	}
	if (!(y > 0 && mp[y - 1][x] / 1 < 0) && !(x > 0 && mp[y][x - 1] / 1 < 0)
		&& (x < xmax && mp[y][x + 1] == 49) && (y < ymax
		&& mp[y + 1][x] == 49 && mp[y + 2][x] == 49))
	{
		map_info->map_copy[y][x] = -9;
		return ("images/wall/9.png"); 
	}
	if (!(y > 0 && mp[y - 1][x] / 1 < 0) && (x > 0 && mp[y][x - 1] / 1 < 0)
		&& !(x < xmax && mp[y][x + 1] == 49) && (y < ymax
		&& mp[y + 1][x] == 49 && mp[y + 2][x] == 49))
	{
		map_info->map_copy[y][x] = -14;
		return ("images/wall/14.png"); 
	}
	if (y == ymax && (mp[y - 1][x] / 1 > 0
		&& mp[y - 1][x] != 49))
	{
		map_info->map_copy[y][x] = -3;
		return("images/wall/3.png");
	}
	if ((y > 0 && mp[y - 1][x] == -13) && (x > 0 && mp[y][x - 1] / 1 < 0)
		&& ((x < xmax && mp[y][x + 1] == 49) || x == xmax)
		&& !(y < ymax && mp[y + 1][x] == 49))
	{
		map_info->map_copy[y][x] = -7;
		return ("images/wall/7.png");
	}
	if ((y > 0 && mp[y - 1][x] == -12) && ((x > 0 && mp[y][x - 1] / 1 < 0)
		|| x == 0) && (x < xmax && mp[y][x + 1] == 49) && !(y < ymax
		&& mp[y + 1][x] == 49))
	{
		map_info->map_copy[y][x] = -1;
		return ("images/wall/1.png");
	}
	if (x < xmax && y > 0 && y < ymax && (mp[y - 1][x] == -9
		|| mp[y - 1][x] == -12 || mp[y - 1][x] == -21) && mp[y][x + 1] != 49)
	{
		map_info->map_copy[y][x] = -12;
		return("images/wall/12.png");
	}
	if (x > 0 && y > 0 && y < ymax && (mp[y - 1][x] == -14
		|| mp[y - 1][x] == -13 || mp[y - 1][x] == -20) && mp[y][x - 1] / 1 > 0)
	{
		map_info->map_copy[y][x] = -13;
		return("images/wall/13.png");
	}
	if (x > 0 && y > 0 && y < ymax && (mp[y - 1][x] == -14
		|| mp[y - 1][x] == -13 || mp[y - 1][x] == -20) && mp[y][x - 1] / 1 < 0)
	{
		map_info->map_copy[y][x] = -20;
		return("images/wall/20.png");
	}
	if (x < xmax && y > 0 && y < ymax && (mp[y - 1][x] == -9
		|| mp[y - 1][x] == -12 || mp[y - 1][x] == -21) && mp[y][x + 1] == 49)
	{
		map_info->map_copy[y][x] = -21;
		return("images/wall/21.png");
	}
	return ("images/player/player_win.png");
}

char	*sl_get_img_path(char type, t_map_info *map_info, t_x_y coord)
{
	if (type == 'P')
	{
		if (map_info->c_num > 0)
			return ("images/player/player_unwin.png");
		else
			return ("images/player/player_win.png");
	}
	if (type == 'E')
	{
		if (map_info->c_num > 0)
			return ("images/exit/exit_unwin.png");
		else
			return ("images/exit/exit_win.png");
	}
	if (type == 'C')
		return ("images/collectible/collectible.png");
	if (type == '0')
		return ("images/floor/floor.png");
	return (sl_wall_finder(map_info, coord));
}

void	sl_redo_link(t_img_stack *stk, t_map_info *map_info, char type)
{
	mlx_delete_image(map_info->mlx, stk->img);
	mlx_delete_texture(stk->texture);
	stk->texture = mlx_load_png(sl_get_img_path(type, map_info, map_info->player));
	stk->img = mlx_texture_to_image(map_info->mlx, stk->texture);
	stk->type = type;
}

void	sl_lstadd_back(t_img_stack **lst, t_map_info *inf, char type, t_x_y xy)
{
	t_img_stack		*curr;
	t_img_stack		*node;

	node = malloc(sizeof(*node));
	if (!node)
		return ;
	node->texture = mlx_load_png(sl_get_img_path(type, inf, xy));
	node->img = mlx_texture_to_image(inf->mlx, node->texture);
	node->type = type;
	node->next = NULL;
	if (!lst || *lst == NULL)
	{
		*lst = node;
		return ;
	}
	curr = *lst;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = node;
}


int	sl_lstsize(t_img_stack *lst)
{
	int		i;
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

void	sl_lstclear(mlx_t *mlx, t_img_stack **lst)
{
	t_img_stack	*temp;
	t_img_stack	*curr;

	if (*lst == NULL)
		return ;
	curr = *lst;
	while (curr->next != NULL)
	{
		temp = curr->next;
		if (curr)
		{
			mlx_delete_image(mlx, curr->img);
			mlx_delete_texture(curr->texture);
			free (curr);
		}
		curr = temp;
	}
	if (curr)
	{
		mlx_delete_image(mlx, curr->img);
		mlx_delete_texture(curr->texture);
		free (curr);
	}
	*lst = NULL;
}

t_img_stack *sl_link_finder(t_img_stack * img_stack, int index)
{
	while(--index >= 0 && img_stack->next)
		img_stack = img_stack->next;
	return (img_stack);
}

t_img_stack	*ft_lstlast(t_img_stack *lst)
{
	t_img_stack	*curr;

	if (lst == NULL)
		return (NULL);
	curr = lst;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	return (curr);
}
