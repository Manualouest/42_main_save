/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_stack_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:35:23 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/03 20:00:37 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include.h"
#include <stdio.h>

char	*sl_get_img_path(char type, t_map_info *map_info)
{
	if (type == 'P')
		return ("images/player/player.png");
	else if (type == 'E')
	{
		if (map_info->c_num > 0)
			return ("images/exit/exit_unwin.png");
		else
			return ("images/exit/exit_win.png");
	}
	else if (type == 'C')
		return ("images/collectible/collectible.png");
	else if (type == '0')
		return ("images/floor/floor.png");
	else if (type == '1')
		return ("images/wall/wall.png");
	return ("images/player/player.png");
}

void	sl_redo_link(t_img_stack *stk, t_map_info *map_info, char type)
{
	mlx_delete_image(map_info->mlx, stk->img);
	mlx_delete_texture(stk->texture);
	stk->texture = mlx_load_png(sl_get_img_path(type, map_info));
	stk->img = mlx_texture_to_image(map_info->mlx, stk->texture);
	stk->type = type;
}

void	sl_lstadd_back(t_img_stack **lst, t_map_info *map_info, char type)
{
	t_img_stack		*curr;
	t_img_stack		*node;

	node = malloc(sizeof(*node));
	if (!node)
		return ;
	node->texture = mlx_load_png(sl_get_img_path(type, map_info));
	node->img = mlx_texture_to_image(map_info->mlx, node->texture);
	node->type = type;
	node->next = NULL;
	if (*lst == NULL)
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
