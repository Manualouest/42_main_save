/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_stack_handler_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:35:23 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/09 17:24:45 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

void	sl_add_back(t_img_stack **lst, t_map_info *inf, char type, t_x_y xy)
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

t_img_stack	*sl_link_finder(t_img_stack *img_stack, int index)
{
	while (--index >= 0 && img_stack->next)
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
