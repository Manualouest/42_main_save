/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:16:18 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/02 18:31:43 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include.h"

void	sl_create_img(void *mlx, t_map_info map_info, t_img_stack **img_stack)
{
	int		i;
	int		ii;

	i = -1;
	while (++i < map_info.size.y)
	{
		ii = -1;
		while (++ii < map_info.size.x)
			sl_lstadd_back(img_stack, mlx, map_info.map[i][ii]);
	}
}

void	sl_img_show(t_mlxs mlxs, t_map_info mp_inf, t_img_stack *img_stk)
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
			mlx_put_image_to_window(mlxs.mlx, mlxs.win, tp_stk->img, ii * 32 + 32, i * 32 + 32);
			if (i < mp_inf.size.y - 6 || (i < mp_inf.size.y - 5 && ii < 26))
				tp_stk = tp_stk->next;
			write(1, &tp_stk->type, 1);
			write(1, "\n", 1);
		}
	}
}

int	main(int argc, char **argv)
{
	t_map_info	map_info;
	t_img_stack	*img_stack;
	t_mlxs		mlxs;

	if (argc != 2)
		exit(0);
	sl_parse_main(argv[1], &map_info);
	img_stack = NULL;
	mlxs.mlx = mlx_init();
	mlxs.win = mlx_new_window(mlxs.mlx, map_info.size.x * 32 + 64, map_info.size.y * 32 + 64, "So Long");
	
	sl_create_img(mlxs.mlx, map_info, &img_stack);
	sl_img_show(mlxs, map_info, img_stack);
	
	mlx_loop(mlxs.mlx);
	
	sl_free_t_map_info(&map_info);
	sl_lstclear(mlxs.mlx, &img_stack);
	mlx_destroy_window(mlxs.mlx, mlxs.win);
	mlx_destroy_display(mlxs.mlx);
}