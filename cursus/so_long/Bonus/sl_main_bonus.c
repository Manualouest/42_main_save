/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:16:18 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/15 20:27:22 by mbirou           ###   ########.fr       */
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
					pxy.x = ii;
					pxy.y = i;
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

void	sl_create_players(t_map_info *map_info, t_gifs *gifs)
{
	char		*png;
	int			i;

	gifs->nowin = malloc(sizeof(**gifs->nowin));
	*gifs->nowin = 0;
	gifs->win = malloc(sizeof(**gifs->win));
	*gifs->win = 0;
	i = 1;
	png = sl_get_png(PLAYER_UNWIN, ft_itoa(i));
	while (i++, png != NULL)
	{
		sl_custom_addback(map_info, png, gifs->nowin, 'P');
		free(png);
		png = sl_get_png(PLAYER_UNWIN, ft_itoa(i));
	}
	free(png);
	i = 1;
	png = sl_get_png(PLAYER_WIN, ft_itoa(i));
	while (i++, png != NULL)
	{
		sl_custom_addback(map_info, png, gifs->win, 'P');
		free(png);
		png = sl_get_png(PLAYER_WIN, ft_itoa(i));
	}
	free(png);
}

void	sl_init_exit_stack(t_map_info *map_info, t_img_stack **stk, char *path)
{
	char		*png;
	int			i;

	i = 1;
	png = sl_get_png(path, ft_itoa(i));
	while (i++, png != NULL)
	{
		sl_custom_addback(map_info, png, stk, 'P');
		free(png);
		png = sl_get_png(path, ft_itoa(i));
	}
	free(png);
}

void	sl_create_exits(t_map_info *map_info, t_gifs *gifs)
{
	gifs->idle = malloc(sizeof(**gifs->idle));
	*gifs->idle = 0;
	gifs->angry = malloc(sizeof(**gifs->angry));
	*gifs->angry = 0;
	gifs->happy = malloc(sizeof(**gifs->happy));
	*gifs->happy = 0;
	gifs->shy = malloc(sizeof(**gifs->shy));
	*gifs->shy = 0;
	gifs->ok = malloc(sizeof(**gifs->ok));
	*gifs->ok = 0;
	gifs->cry = malloc(sizeof(**gifs->cry));
	*gifs->cry = 0;
	gifs->sus = malloc(sizeof(**gifs->sus));
	*gifs->sus = 0;
	sl_init_exit_stack(map_info, gifs->idle, EXIT_IDLE);
	sl_init_exit_stack(map_info, gifs->angry, EXIT_ANGRY);
	sl_init_exit_stack(map_info, gifs->happy, EXIT_HAPPY);
	sl_init_exit_stack(map_info, gifs->shy, EXIT_SHY);
	sl_init_exit_stack(map_info, gifs->ok, EXIT_OK);
	sl_init_exit_stack(map_info, gifs->cry, EXIT_CRY);
	sl_init_exit_stack(map_info, gifs->sus, EXIT_SUS);
}

void	sl_show_gif(mlx_t *mlx, t_img_stack *img_stk, t_x_y xy)
{
	int	tp;

	tp = 0;
	while (tp++, img_stk && img_stk->next)
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

t_x_y	sl_get_exit(t_map_info map_info)
{
	t_x_y	xy;
	int		i;
	int		ii;

	i = -1;
	while (++i < map_info.size.y)
	{
		ii = -1;
		while (++ii < map_info.size.x)
		{
			if (map_info.map[i][ii] == 'E')
			{
				xy.x = ii;
				xy.y = i;
				break ;
			}
		}
	}
	return(xy);
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
	// map_info.gifs = malloc(sizeof(*map_info.gifs));
	// map_info.gifs->player_frame = 0;
	// map_info.gifs->exit_frame = 0;
	// map_info.gifs->player_type = 0;
	// map_info.gifs->exit_type = 0;
	if (sl_mlx_handler(map_info, &floor) == 0)
		exit(0);
	return (0);
}
