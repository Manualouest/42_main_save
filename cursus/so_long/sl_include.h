/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_include.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:23:05 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/07 02:08:16 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_INCLUDE_H
# define SL_INCLUDE_H

# include "extras/extras.h"
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_parse_util
{
	int			p_num;
	int			e_num;
}				t_parse_util;

typedef struct s_x_y
{
	int			x;
	int			y;
}				t_x_y;

typedef struct s_map_info
{
	char				**map;
	char				**map_copy;
	t_x_y				size;
	int					c_num;
	t_x_y				player;
	struct s_img_stack	**player_img;
	struct s_img_stack	**img_stack;
	mlx_t				*mlx;
	int					total_moves;
}						t_map_info;

typedef struct s_img_stack
{
	mlx_image_t			*img;
	mlx_texture_t		*texture;
	char				type;
	struct s_img_stack	*next;
}						t_img_stack;

int			sl_free_t_map_info(t_map_info *map_info);
int			sl_parsing_error(int err, t_map_info *mp_inf, char **extra, int freem);
void		sl_get_map(char *file_name, char **map_full, int *tpint);

int			sl_lstsize(t_img_stack *lst);
void		sl_redo_link(t_img_stack *stk, t_map_info *map_info, char type);
void		sl_lstclear(mlx_t *mlx, t_img_stack **lst);
void		sl_lstadd_back(t_img_stack **lst, t_map_info *map_info, char type, t_x_y xy);
t_img_stack	*ft_lstlast(t_img_stack *lst);
t_img_stack *sl_link_finder(t_img_stack * img_stack, int index);

int			sl_parse_main(char *map_file, t_map_info *map_info);

#endif