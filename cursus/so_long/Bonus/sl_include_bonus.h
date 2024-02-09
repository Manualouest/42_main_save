/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_include_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:23:05 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/09 19:26:33 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_INCLUDE_BONUS_H
# define SL_INCLUDE_BONUS_H

# include "../extras/extras.h"
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"

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

typedef struct s_img_stack
{
	char				type;
	mlx_image_t			*img;
	mlx_texture_t		*texture;
	struct s_img_stack	*next;
}						t_img_stack;

typedef struct s_exits
{
	int			exit_type;
	int			exit_frame;
	t_x_y		exit;
	t_img_stack	**idle;
	t_img_stack	**angry;
	t_img_stack	**happy;
	t_img_stack	**shy;
	t_img_stack	**ok;
	t_img_stack	**cry;
	t_img_stack	**sus;
}				t_exits;

typedef struct s_players
{
	int			player_type;
	int			player_frame;
	t_x_y		xy;
	t_img_stack	**nowin;
	t_img_stack	**win;
}				t_players;

typedef struct s_map_info
{
	int					total_moves;
	int					c_num;
	char				**map;
	char				**map_copy;
	mlx_t				*mlx;
	t_x_y				size;
	struct s_exits		exits;
	struct s_players	players;
	struct s_img_stack	**img_stack;
}						t_map_info;

int			sl_free_t_map_info(t_map_info *map_info);
int			sl_parsing_error(int err, t_map_info *mp_inf, char **xtra, int fr);
void		sl_get_map(char *file_name, char **map_full, int *tpint);

int			sl_next(t_map_info *map_info, int way);
void		sl_update_moves(t_map_info *map_info);
void		sl_change_exit(t_map_info *map_info, int old_type, int ex, int ey);
void		sl_change_player(t_map_info *map_info, int play);
void		sl_move_player(t_map_info *mp_inf, int way);

int			sl_is_in_circle(t_map_info map_info, int rad, int ex, int ey);

void		ft_putnbr(int n);
void		sl_create_img(t_map_info mp_inf, t_img_stack **img_stk);
void		sl_img_show(mlx_t *mlx, t_map_info mp_inf, t_img_stack *img_stk);

void		sl_win_stop(t_map_info *map_info);
void		sl_single_key_handler(mlx_key_data_t keydata, void *map_info_void);
void		sl_handle_extra_floor(t_map_info mp_inf, t_img_stack **floor);
int			sl_mlx_handler(t_map_info map_info, t_img_stack *floor);

int			sl_lstsize(t_img_stack *lst);
void		sl_redo_link(t_img_stack *stk, t_map_info *map_info, char type);
void		sl_lstclear(mlx_t *mlx, t_img_stack **lst);
void		sl_add_back(t_img_stack **lst, t_map_info *inf, char tp, t_x_y xy);
t_img_stack	*ft_lstlast(t_img_stack *lst);
t_img_stack	*sl_link_finder(t_img_stack *img_stack, int index);

int			sl_parse_main(char *map_file, t_map_info *map_info);

void		sl_redo_link(t_img_stack *stk, t_map_info *map_info, char type);
char		*sl_get_img_path(char type, t_map_info *map_info, t_x_y coord);

char		*sl_wall_finder1(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder2(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder3(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder4(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder5(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder6(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder7(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder8(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder9(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder10(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder11(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder12(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder13(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder14(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder15(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder16(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder17(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder18(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder19(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder20(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder21(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder22(t_map_info *map_info, int x, int y, int xmax);
char		*sl_wall_finder23(t_map_info *map_info, int x, int y, int xmax);

char		*sl_exit_finder(t_map_info *map_info);
void		sl_switch_exit(t_map_info *map_info, int ex, int ey);
void		sl_load_players(t_map_info *map_info, char *player);

#endif