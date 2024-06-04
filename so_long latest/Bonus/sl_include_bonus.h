/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_include_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:23:05 by mbirou            #+#    #+#             */
/*   Updated: 2024/04/09 02:32:43 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_INCLUDE_BONUS_H
# define SL_INCLUDE_BONUS_H

# include "../extras/extras.h"
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>

# define EXIT_IDLE "images/exit/exit_idle_bonus/"
# define EXIT_ANGRY "images/exit/exit_angry_bonus/"
# define EXIT_HAPPY "images/exit/exit_happy_bonus/"
# define EXIT_SHY "images/exit/exit_shy_bonus/"
# define EXIT_OK "images/exit/exit_ok_bonus/"
# define EXIT_CRY "images/exit/exit_cry_bonus/"
# define EXIT_SUS "images/exit/exit_sus_bonus/"

# define PLAYER_UNWIN "images/player/player_unwin_bonus/"
# define PLAYER_WIN "images/player/player_win_bonus/"

# define COUNTER_MOVE "images/counter/move/"
# define COUNTER_COLLECT "images/counter/collect/"

# define HIVE "images/hive/"
# define HIVE_TOP "images/hive/dancing_top/"
# define BEE "images/bees/"

# define SOUND_LOW "paplay --volume=25000 sounds/"
# define SOUND_LOUD "paplay --volume=40000 sounds/"

typedef struct s_parse_util
{
	int					p_num;
	int					e_num;
}						t_parse_util;

typedef struct s_x_y
{
	int					x;
	int					y;
}						t_x_y;

typedef struct s_img_stack
{
	int					is_shown;
	int					gif_len;
	char				type;
	char				*path;
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
	int					exit_sound_frame;
	t_x_y				exit;
	struct s_img_stack	**idle;
	struct s_img_stack	**angry;
	struct s_img_stack	**happy;
	struct s_img_stack	**shy;
	struct s_img_stack	**ok;
	struct s_img_stack	**cry;
	struct s_img_stack	**sus;
}						t_gifs;

typedef struct s_counter
{
	int					move;
	int					collect;
	struct s_img_stack	**counter_move;
	struct s_img_stack	**counter_collect;
}						t_counter;

typedef struct s_bees
{
	int					num;
	int					is_angry;
	int					way;
	int					bee_frame;
	int					wait_frame;
	t_x_y				bee_pos;
	t_x_y				target;
	struct s_img_stack	**img_stack;
	struct s_bees		*next;
}						t_bees;

typedef struct s_hive
{
	int					bee_count;
	int					honey_level;
	int					flowers_brought;
	int					hive_frame;
	char				**tp_map;
	t_x_y				size;
	t_x_y				hive_pos;
	struct s_bees		**bees;
	struct s_img_stack	**hive_bot;
	struct s_img_stack	**hive_top;
}						t_hive;

typedef struct s_end_gif
{
	int					sound_frame;
	int					gif_frame;
	int					nb_instances;
	int					loops;
	char				*path;
	struct s_img_stack	**img_stack;
}						t_end_gif;

typedef struct s_map_info
{
	int					total_moves;
	int					c_num;
	int					way;
	int					has_won;
	char				**map;
	char				**map_copy;
	mlx_t				*mlx;
	t_x_y				size;
	struct s_gifs		*gifs;
	struct s_hive		*hive;
	struct s_counter	*counter;
	struct s_end_gif	*end_gif;
	struct s_img_stack	**img_stack;
	struct s_img_stack	**floor;
}						t_map_info;

typedef struct s_wall_utils
{
	int					x;
	int					y;
	int					xmax;
}						t_wu;

// sl_animations_bonus.c
void		sl_anime_player(void *mp_info);
void		sl_anime_exit_main(void *map_info);
void		sl_update_pos(t_img_stack *stk, t_img_stack **curr,
				t_map_info *map_info);
t_img_stack	*sl_get_next_exit_png(t_img_stack *stk, t_img_stack **exit);
void		sl_anime_get_exit(t_img_stack	***exit, t_map_info	*mp_inf);

// sl_animations_utils_bonus.c
void		sl_repeat_key_handler(mlx_key_data_t keydata, t_map_info *mp_inf);
void		sl_show_png(t_img_stack *stk, t_map_info *map_info, t_x_y xy);
void		sl_key_handler(mlx_key_data_t keydata, void *map_info_void);
int			sl_next(t_map_info *map_info, int way);
t_gifs		sl_init_gifs(t_map_info *map_info);

// sl_bees_handler_bonus.c
void		sl_anime_bees_main(t_hive *hive, t_map_info *map_info);
void		sl_move_bees_main(t_map_info *map_info, t_hive *hive);
void		sl_get_bee_target(t_map_info *map_info, t_bees *bee);
void		sl_move_bee(t_map_info *map_info, t_bees *bee);
void		sl_hide_bee(t_bees *bee, t_map_info *map_info);

// sl_bees_handler_utils_bonus.c
int			sl_move_bee_on_x(t_bees *bee, t_map_info *map_info);
int			sl_move_bee_on_y(t_bees *bee, t_map_info *map_info);
void		sl_start_angry_mode(t_map_info *map_info, t_bees *bee);
void		sl_check_is_flower(t_bees *bee, t_hive *hive, t_map_info *map_info);
void		sl_transfer_angry_mode(t_bees *bees, t_bees *angry_bee);

// sl_counter_handler_bonus.c
void		sl_redo_itoa(char **var, int num, int is_redo, int is_free_only);
int			sl_num_len(int num);
void		sl_update_moves(t_map_info *map_inf);
void		sl_redo_counter_collect(t_map_info *map_info, int new_set);
void		sl_redo_counter_move(t_map_info *map_info, int new_set);

// sl_end_gif_setup_bonus.c
void		sl_start_end_gif(t_map_info *map_info);
void		sl_end_gif_loop(void *vmap_info);
void		sl_add_an_instance(t_map_info *map_info, t_end_gif *end_gif);
void		sl_animate_all_instances(t_end_gif *end_gif);
void		sl_get_end_gif(t_map_info *map_info, t_end_gif *end_gif);

// sl_end_gif_utils_bonus.c
void		sl_coord_changer(t_img_stack *stk);
void		sl_hide_everything(t_map_info *map_info, t_bees *bees);
t_x_y		sl_get_rand_pos(t_map_info *map_info);
void		sl_redo_end_song(t_end_gif *end_gif);
int			sl_is_pos_equal(t_x_y pos1, t_x_y pos2);

// sl_free_error_bonus.c
int			sl_free_t_map_info(t_map_info *map_info);
int			sl_parsing_error(int err, t_map_info *mp_inf,
				char **extra, int freem);
void		sl_get_map(char *file_name, char **map_full, int *tpint);
void		sl_free_gifs(t_map_info *map_info, t_img_stack **floor);
void		sl_free_hive(t_map_info *map_info, t_img_stack **floor);

// sl_gif_mover_bonus.c
void		sl_switch_exit(t_map_info *map_info, int old_type);
void		sl_change_exit(t_map_info *mp_info, int old_type, int ex, int ey);
void		sl_switch_player(t_gifs *gifs);
void		sl_secure_player(t_map_info *map_info);
void		sl_move_player(t_map_info *mp_inf, int way);

// sl_handle_sounds_bonus.c
void		sl_launch_sound(char *type);
void		sl_do_sound_6(t_gifs *gifs);
void		sl_handle_exit_sound(t_gifs *gifs, t_map_info *map_info);
void		sl_cross_close(void	*param);

// sl_hive_handler_bonus.c
void		sl_show_top_hive(t_img_stack *stk, t_map_info *map_info, t_x_y xy);
void		sl_hive_radar_check(t_map_info *map_info, t_hive *hive);
void		sl_handle_bottom_hive(t_map_info *map_info, t_hive *hive);
void		sl_animate_hive(void *map_info);

// sl_hive_setup_bonus.c
void		sl_hive_init(t_map_info *map_info, t_hive *hive);
t_bees		*sl_create_bees(t_map_info *map_info, t_hive *hive);
t_img_stack	*sl_insert_bees(t_map_info *map_info, t_hive *hive);
void		sl_place_hive(t_hive *hive, t_map_info *map_info);
int			sl_check_try(t_map_info *map_info, t_x_y pos, t_x_y xy);

// sl_hive_setup_utils_bonus.c
t_x_y		sl_get_hive_pos(t_map_info *map_info);
t_x_y		sl_scanner_horizontal(t_hive *hive, t_map_info *map_info, int rad);
t_x_y		sl_scanner_vertical(t_hive *hive, t_map_info *map_info, int rad);
void		sl_redo_map_copy(t_map_info *map_info);
int			sl_get_bee_num(int num);

// sl_math_utils_bonus.c
int			sl_is_in_circle(t_map_info map_info, int rad, int ex, int ey);
int			sl_power(int i, int p);
int			sl_base_change(int nbr, char *base);

// sl_misc_handlers_bonus.c
void		sl_print_emoji(int choice);
void		sl_win_stop(t_map_info *map_info, int win_loose);
void		sl_handle_extra_floor(t_map_info mp_inf, t_img_stack **floor);
void		sl_loops(t_map_info map_info);
int			sl_mlx_handler(t_map_info map_info, t_img_stack **floor);

// sl_other_utils_bonus.c
void		ft_putnbr(int n);
void		sl_update_c_num(t_map_info *map_info);
int			ft_lstsize(t_img_stack *lst);

// sl_parsing_bonus.c
int			sl_check_tile_utile(t_map_info *m_inf, t_parse_util *parse_ut,
				t_x_y xy, t_x_y *pxy);
int			sl_check_tiles(t_map_info *m_inf, t_x_y *pxy);
void		sl_path_check_utils(t_map_info *map_info, int x, int y);
int			sl_path_check(t_map_info *map_info, char *original_map, t_x_y xy);
int			sl_parse_main(char *map_file, t_map_info *map_info);

// sl_parsing_utils_bonus.c
int			sl_has_empty_lines(char *map_full);
int			check_file_type(char *map_file);

// sl_setup_images_bonus.c
void		sl_create_img(t_map_info mp_inf, t_img_stack **img_stk);
void		sl_img_show(mlx_t *mlx, t_map_info mp_inf, t_img_stack *img_stk);
void		sl_custom_addback(t_map_info *map_info, char *png,
				t_img_stack **lst, char type);
void		sl_instant_add_png(t_map_info *map_info, t_img_stack **stk,
				char *path, int frame);
void		sl_show_gif(mlx_t *mlx, t_img_stack *img_stk, t_x_y xy);

// sl_setup_struct_bonus.c
void		sl_create_players(t_map_info *map_info, t_gifs *gifs);
void		sl_create_exits(t_map_info *map_info, t_gifs *gifs);
void		sl_init_exit_stack(t_map_info *map_info, t_img_stack **stk,
				char *path, int gif_len);
void		sl_init_counter(t_map_info *map_info, t_counter *counter);
int			main(int argc, char **argv);

// sl_setup_utils_bonus.c
t_x_y		sl_get_link(t_map_info *map_info, char type);
char		*sl_get_png(char *path, char *tp);
t_x_y		sl_get_exit(t_map_info map_info);
t_x_y		sl_get_player(t_map_info map_info);

// sl_stack_handler_bonus.c
void		sl_add_back(t_img_stack **lst, t_map_info *inf,
				char type, t_x_y xy);
int			sl_lstsize(t_img_stack *lst);
void		sl_lstclear(mlx_t *mlx, t_img_stack **lst);
t_img_stack	*sl_link_finder(t_img_stack *img_stack, int index);
t_img_stack	*ft_lstlast(t_img_stack *lst);

// sl_texture_handler(0-5)_bonus.c
char		*sl_get_img_path(char type, t_map_info *map_info, t_x_y coord);
void		sl_init_func_list(void **funcs);
char		*sl_wall_finder_main(t_map_info *map_info, t_x_y coord);
char		*sl_wall_finder(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder1(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder2(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder3(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder4(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder5(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder6(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder7(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder8(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder9(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder10(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder11(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder12(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder13(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder14(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder15(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder16(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder17(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder18(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder19(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder20(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder21(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder22(t_map_info *map_info, int *x, int *y, int xmax);
char		*sl_wall_finder23(t_map_info *map_info, int *x, int *y, int xmax);

#endif