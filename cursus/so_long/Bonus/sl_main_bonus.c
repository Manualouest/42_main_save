/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:16:18 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/10 15:30:08 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

t_x_y	sl_create_img(t_map_info mp_inf, t_img_stack **img_stk)
{
	int		i;
	int		ii;
	t_x_y	xy;
	t_x_y	pxy;

	i = -1;
	while (++i < mp_inf.size.y)
	{
		ii = -1;
		while (++ii < mp_inf.size.x)
		{
			xy.y = i;
			xy.x = ii;
			if (mp_inf.map_copy[i][ii] == 'P' || mp_inf.map_copy[i][ii] == 'E')
			{
				if (mp_inf.map_copy[i][ii] == 'P')
				{
					pxy.x = 10;
					pxy.y = 5;
				}
				sl_add_back(img_stk, &mp_inf, '0', xy);
			}
			else
				sl_add_back(img_stk, &mp_inf, mp_inf.map_copy[i][ii], xy);
		}
	}
	return (pxy);
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

t_x_y	sl_get_link(t_map_info *map_info, char type)
{
	int			i;
	int			ii;
	t_x_y		exit_coord;

	i = -1;
	while (++i < map_info->size.y)
	{
		ii = -1;
		while (++ii < map_info->size.x)
		{
			if (map_info->map[i][ii] == type)
			{
				exit_coord.x = ii;
				exit_coord.y = i;
				break ;
			}
		}
	}
	return (exit_coord);
}

void	sl_custom_addback(t_map_info *map_info, char *png, t_img_stack **lst, char type)
{
	t_img_stack	*curr;
	t_img_stack	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return ;
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
#include <stdio.h>
char	*sl_get_png(char *path, char *tp)
{
	char	*png;
	int		fd;
	int		check;

	png = gnl_strlcat(path, tp, 0);
	png = gnl_strlcat(png, ".png", 1);
	fd = open(png, O_RDONLY);
	free(tp);
	if (fd > 0)
	{
		tp = malloc(2);
		tp[1] = 0;
		check = read(fd, tp, 1);
		close(fd);
		free(tp);
		if (check > 0)
			return (png);
	}
	free(png);
	return (NULL);
}

t_players	*sl_create_players(t_map_info map_info)
{
	t_players	*players;
	char		*png;
	int			i;

	players = malloc(sizeof(*players));;
	players->nowin = malloc(sizeof(**players->nowin));
	i = 1;
	png = sl_get_png(PLAYER_UNWIN, ft_itoa(i));
	while (i++, png != NULL)
	{
		sl_custom_addback(&map_info, png, players->nowin, 'P');
		free(png);
		png = sl_get_png(PLAYER_UNWIN, ft_itoa(i));
	}
	free(png);
	players->win = malloc(sizeof(**players->win));
	players->win = NULL;
	i = 1;
	png = sl_get_png(PLAYER_UNWIN, ft_itoa(i));
	while (i++, png != NULL)
	{
		sl_custom_addback(&map_info, png, players->win, 'P');
		free(png);
		png = sl_get_png(PLAYER_UNWIN, ft_itoa(i));
	}
	free(png);
	return(players);
}

int	main(int argc, char **argv)
{
	t_map_info	map_info;
	t_img_stack	*img_stack;
	t_img_stack	*floor;

	// write(1, "\E[H\E[2J", 7);
	if (argc != 2 || !sl_parse_main(argv[1], &map_info))
		exit (0);
	img_stack = NULL;
	floor = NULL;
	map_info.img_stack = &img_stack;
	map_info.total_moves = 0;
	if (sl_mlx_handler(map_info, &floor) == 0)
		exit(0);
	return (0);
}
