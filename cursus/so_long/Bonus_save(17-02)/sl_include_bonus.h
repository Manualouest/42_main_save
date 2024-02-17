/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_include_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:23:05 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/16 18:46:56 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_INCLUDE_BONUS_H
# define SL_INCLUDE_BONUS_H

# include "../extras/extras.h"
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define EXIT_IDLE "images/exit/exit_idle_bonus/"
# define EXIT_ANGRY "images/exit/exit_angry_bonus/"
# define EXIT_HAPPY "images/exit/exit_happy_bonus/"
# define EXIT_SHY "images/exit/exit_shy_bonus/"
# define EXIT_OK "images/exit/exit_ok_bonus/"
# define EXIT_CRY "images/exit/exit_cry_bonus/"
# define EXIT_SUS "images/exit/exit_sus_bonus/"
# define PLAYER_UNWIN "images/player/player_unwin_bonus/"
# define PLAYER_WIN "images/player/player_win_bonus/"

typedef struct s_parse_util
{
	int				p_num;
	int				e_num;
}				t_parse_util;

typedef struct s_x_y
{
	int			x;
	int			y;
}				t_x_y;

typedef struct s_img_stack
{
	int					is_shown;
	char				type;
	mlx_image_t			*img;
	mlx_texture_t		*texture;
	struct s_img_stack	*next;
}						t_img_stack;

typedef struct s_gifs
{
	int					player_frame;
	int					player_type;
	t_x_y				xy;
	struct s_img_stack	**nowin;
	struct s_img_stack	**win;
	int					exit_frame;
	int					exit_type;
	t_x_y				exit;
	struct s_img_stack	**idle;
	struct s_img_stack	**angry;
	struct s_img_stack	**happy;
	struct s_img_stack	**shy;
	struct s_img_stack	**ok;
	struct s_img_stack	**cry;
	struct s_img_stack	**sus;
}						t_gifs;

typedef struct s_map_info
{
	int					total_moves;
	int					c_num;
	char				**map;
	char				**map_copy;
	mlx_t				*mlx;
	t_x_y				size;
	struct s_gifs		*gifs;
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
int			ft_lstsize(t_img_stack *lst);

void		ft_putnbr(int n);
t_x_y		sl_create_img(t_map_info mp_inf, t_img_stack **img_stk);
void		sl_img_show(mlx_t *mlx, t_map_info mp_inf, t_img_stack *img_stk);

void		sl_win_stop(t_map_info *map_info);
void		sl_single_key_handler(mlx_key_data_t keydata, void *map_info_void);
void		sl_handle_extra_floor(t_map_info mp_inf, t_img_stack **floor);
int			sl_mlx_handler(t_map_info map_info, t_img_stack **floor);

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

t_x_y		sl_get_exit(t_map_info map_info);
void		sl_create_exits(t_map_info *map_info, t_gifs *gifs);
char		*sl_exit_finder(t_map_info *map_info);
// t_exits		sl_exits_maker(t_map_info *map_info);
t_x_y		sl_get_link(t_map_info *map_info, char type);
// t_players	*sl_players_maker(t_map_info *map_inf);

void		sl_create_players(t_map_info *map_info, t_gifs *gifs);
void		sl_show_gif(mlx_t *mlx, t_img_stack *img_stk, t_x_y xy);
void		sl_switch_player(t_gifs *gifs);

#endif