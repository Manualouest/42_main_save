/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_setup_images_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:51:40 by mbirou            #+#    #+#             */
/*   Updated: 2024/03/28 19:54:17 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

void	sl_create_img(t_map_info mp_inf, t_img_stack **img_stk)
{
	int		i;
	int		ii;
	t_x_y	xy;

	i = -1;
	while (++i < mp_inf.size.y)
	{
		ii = -1;
		while (++ii < mp_inf.size.x)
		{
			xy.y = i;
			xy.x = ii;
			if (mp_inf.map_copy[i][ii] == 'P' || mp_inf.map_copy[i][ii] == 'E'
				|| mp_inf.map_copy[i][ii] == 'H')
			{
				sl_add_back(img_stk, &mp_inf, '0', xy);
			}
			else
				sl_add_back(img_stk, &mp_inf, mp_inf.map_copy[i][ii], xy);
		}
	}
}

void	sl_img_show(mlx_t *mlx, t_map_info mp_inf, t_img_stack *img_stk)
{
	t_img_stack	*tp_stk;
	int			i;
	int			ii;

	i = -1;
	tp_stk = img_stk;
	while (++i < mp_inf.size.y)
	{
		ii = -1;
		while (++ii < mp_inf.size.x)
		{
			mlx_image_to_window(mlx, tp_stk->img, ii * 42 + 16, i * 42 + 16);
			tp_stk = tp_stk->next;
		}
	}
}

void	sl_custom_addback(t_map_info *map_info, char *png,
	t_img_stack **lst, char type)
{
	t_img_stack	*curr;
	t_img_stack	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return ;
	node->is_shown = 0;
	node->texture = mlx_load_png(png);
	node->img = mlx_texture_to_image(map_info->mlx, node->texture);
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

void	sl_instant_add_png(t_map_info *map_info, t_img_stack **stk,
	char *path, int frame)
{
	char	*png;

	png = sl_get_png(path, ft_itoa(frame));
	if (png != NULL)
	{
		if (path[7] == 'p')
			sl_custom_addback(map_info, png, stk, 'P');
		else
			sl_custom_addback(map_info, png, stk, 'E');
	}
	free(png);
}

void	sl_show_gif(mlx_t *mlx, t_img_stack *img_stk, t_x_y xy)
{
	while (img_stk && img_stk->next)
	{
		mlx_image_to_window(mlx, img_stk->img, xy.x * 42 + 16, xy.y * 42 + 16);
		img_stk->img->instances->enabled = 0;
		img_stk = img_stk->next;
	}
	if (img_stk)
	{
		mlx_image_to_window(mlx, img_stk->img, xy.x * 42 + 16, xy.y * 42 + 16);
		img_stk->img->instances->enabled = 0;
	}
}
