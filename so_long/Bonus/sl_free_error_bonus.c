/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_error_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:24:23 by mbirou            #+#    #+#             */
/*   Updated: 2024/03/28 19:35:15 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

int	sl_free_t_map_info(t_map_info *map_info)
{
	int	i;

	i = -1;
	if (map_info->map)
	{
		while (map_info->map[++i] != 0)
			free(map_info->map[i]);
		free(map_info->map[i]);
		free(map_info->map);
		i = -1;
	}
	if (map_info->map_copy)
	{
		while (map_info->map_copy[++i] != 0)
			free(map_info->map_copy[i]);
		free(map_info->map_copy[i]);
		free(map_info->map_copy);
	}
	return (0);
}

int	sl_parsing_error(int err, t_map_info *mp_inf, char **extra, int freem)
{
	if (err == 2)
		write(2, "Map edges invalid.\n", 19);
	else if (err == 3)
		write(2, "Invalid character detected.\n", 28);
	else if (err == 4)
		write(2, "Your map isn't a rectangle.\n", 28);
	else if (err == 5)
		write(2, "Wrong number of player, exit or collectible.\n", 45);
	else if (err == 6)
		write(2, "The map is impossible to complete.\n", 35);
	if (freem)
		sl_free_t_map_info(mp_inf);
	free(*extra);
	return (0);
}

void	sl_get_map(char *file_name, char **map_full, int *tpint)
{
	char	*n_line;

	*tpint = open(file_name, O_RDONLY);
	n_line = gnl(*tpint);
	if (n_line == NULL)
		return ;
	*map_full = NULL;
	while (n_line != NULL)
	{
		*map_full = gnl_strlcat(*map_full, n_line, 1);
		free(n_line);
		n_line = gnl(*tpint);
	}
	free(n_line);
}

void	sl_free_gifs(t_map_info *map_info, t_img_stack **floor)
{
	sl_free_t_map_info(map_info);
	sl_lstclear(map_info->mlx, map_info->img_stack);
	sl_lstclear(map_info->mlx, floor);
	sl_lstclear(map_info->mlx, map_info->gifs->win);
	sl_lstclear(map_info->mlx, map_info->gifs->nowin);
	sl_lstclear(map_info->mlx, map_info->gifs->idle);
	sl_lstclear(map_info->mlx, map_info->gifs->angry);
	sl_lstclear(map_info->mlx, map_info->gifs->happy);
	sl_lstclear(map_info->mlx, map_info->gifs->shy);
	sl_lstclear(map_info->mlx, map_info->gifs->ok);
	sl_lstclear(map_info->mlx, map_info->gifs->cry);
	sl_lstclear(map_info->mlx, map_info->gifs->sus);
	free(map_info->gifs->win);
	free(map_info->gifs->nowin);
	free(map_info->gifs->idle);
	free(map_info->gifs->angry);
	free(map_info->gifs->happy);
	free(map_info->gifs->shy);
	free(map_info->gifs->ok);
	free(map_info->gifs->cry);
	free(map_info->gifs->sus);
	sl_lstclear(map_info->mlx, map_info->counter->counter_move);
	free(map_info->counter->counter_move);
	sl_lstclear(map_info->mlx, map_info->counter->counter_collect);
	free(map_info->counter->counter_collect);
}

void	sl_free_hive(t_map_info *map_info, t_img_stack **floor)
{
	t_bees	*bees;
	t_bees	*prev;

	bees = *map_info->hive->bees;
	while (bees != NULL)
	{
		sl_lstclear(map_info->mlx, bees->img_stack);
		free(bees->img_stack);
		prev = bees;
		bees = bees->next;
		free(prev);
	}
	free(map_info->hive->bees);
	sl_lstclear(map_info->mlx, map_info->hive->hive_bot);
	sl_lstclear(map_info->mlx, map_info->hive->hive_top);
	free(map_info->hive->hive_bot);
	free(map_info->hive->hive_top);
	sl_free_gifs(map_info, floor);
}
