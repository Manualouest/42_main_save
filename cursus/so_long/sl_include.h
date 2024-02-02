/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_include.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:23:05 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/02 18:02:12 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_INCLUDE_H
# define SL_INCLUDE_H

# include "extras/extras.h"
# include <fcntl.h>
# include "MacroLibX/includes/mlx.h"

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
	char		**map;
	char		**map_copy;
	t_x_y		size;
	int			c_num;
	t_x_y		player;
}				t_map_info;

typedef struct s_mlx_stuff
{
	void		*win;
	void		*mlx;
}				t_mlxs;


typedef struct s_img_stack
{
	void				*img;
	char				type;
	struct s_img_stack	*next;
}						t_img_stack;

int		sl_free_t_map_info(t_map_info *map_info);
int		sl_parsing_error(int err, t_map_info *mp_inf, char **extra, int freem);
void	sl_get_map(char *file_name, char **map_full, int *tpint);

int		sl_lstsize(t_img_stack *lst);
void	sl_lstclear(void *mlx, t_img_stack **lst);
void	sl_lstadd_back(t_img_stack **lst, void *mlx, char type);

int		sl_parse_main(char *map_file, t_map_info *map_info);



#endif