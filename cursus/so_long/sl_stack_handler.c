/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_stack_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:35:23 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/02 18:08:36 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include.h"

static char	*sl_get_img_path(char type)
{
	if (type == 'P')
		return ("images/player/player.png");
	else if (type == 'E')
		return ("images/exit/exit.png");
	else if (type == 'C')
		return ("images/collectible/collectible.png");
	else if (type == '0')
		return ("images/floor/floor.png");
	else if (type == '1')
		return ("images/wall/wall.png");
	return ("error ig");
}

// void	sl_lstadd_front(t_img_stack **lst, void *mlx, char type)
// {
	
// 	t_img_stack	*node;

// 	node = malloc(sizeof(*node));
// 	if (!node)
// 		return ;
// 	node->img = mlx_png_file_to_image(mlx, sl_get_img_path(type), NULL, NULL);
// 	node->type = type;
// 	node->next = NULL;
// 	if (*lst != NULL)
// 		node->next = *lst;
// 	*lst = node;
// }

void	sl_lstadd_back(t_img_stack **lst, void *mlx, char type)
{
	t_img_stack	*curr;
	t_img_stack	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return ;
	// type = 'P';
	node->img = mlx_png_file_to_image(mlx, sl_get_img_path(type), NULL, NULL);
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

void	sl_lstclear(void *mlx, t_img_stack **lst)
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
			mlx_destroy_image(mlx, curr->img);
			free (curr);
		}
		curr = temp;
	}
	if (curr)
		free (curr);
	*lst = NULL;
}
