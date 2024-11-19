/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:27:38 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 13:02:46 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

/*------------------- INCLUDES ----------------------*/

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include <unistd.h>
# include <MLX42/MLX42.h>
# include <libft.h>
# include <cub3d_bonus_strucs.h>

/*---------------- DEFINE VALUES ----------------*/
// --Speeds
# define RUNNING_SPEED 5.F
# define CROUCH_SPEED 0.75F
# define WALKING_SPEED 2.F
# define CAMERA_SPEED 0.03F
# define ROTATE_SPEED 0.0025F

//--Heights
# define CROUCH_HEIGHT -0.1F
# define NORMAL_HEIGHT 0.05F
# define JOG_HEIGHT 0.045F

/*---------------- ERROR MSG --------------------*/

# define CUB_ERR ".cub file required\n"
# define PNG_ERR ".png file required\n"
# define FORMAT_ERR "The map doesn't follow the game's format: \n"
# define BAD_CHAR "Invalid character in map\n"
# define BAD_MAP "Map borders are invalid\n"
# define BAD_STEP "Step error\n"
# define BAD_TXT_NAME "Texture has an invalid definition\n"
# define BAD_MAPS "One of the texture maps is bigger than the wall map\n"
# define NO_TEXTURE "Mlx could not load texture\n"
# define PICK_MISSING "Pickaxe textures are missing\n"

/*----------------- FONCTIONS -------------------*/

// -----init-------------------------------------------------------------------
// --init_structs.c
t_game		cd_init_structs(char *map_file);

// --init_tabs.c
int			**cd_get_empty_tab(void);
void		cd_init_graphic(t_game *game);

// ------parsing---------------------------------------------------------------
// --parser.c
void		parser(t_game *game);
void		get_infos(t_game *game);
void		scanner(char *line, t_game *game, int *true_line);
int			is_direction(char *line, int i, int *true_line, t_game *game);
int			is_rgb(char *line, int i, int *true_line, t_game *game);

// --map_handler.c
void		cd_setup_map(char *line, t_game *game, int ***map);
void		cd_setup_txt_maps(char *line, t_game *game, int ***map, int step);

// --check.c
void		check_name_cub(char *path, t_game *game);
void		check_name_png(char *path, t_game *game, char *o_line);

// -----utils------------------------------------------------------------------

// --string_utils.c
void		format_d_tab(char *paths[7]);
void		skip_direction(char *line, int *ii);
char		*format_d_line(char *line, int *ii);

// --tab_utils.c
char		**add_new_line(char *line, char **tab);
float		*cd_add_flst(float *list, float new);

// --math.c
float		cd_clamp(float num, float min, float max);
float		cd_clamp_two(float num, float min, float max);

// --controllers.c
void		player_speed_controller(t_game *game);
void		player_height_controller(t_game *game);
void		mouse_controller(t_game *game);

// --array_utils.c
int			cd_intlen(int *line);
int			*cd_strtoi_m(char *line, int line_len, int dif);
int			cd_array_len(int	**array);
int			**cd_add_new_array_line(int *line, int **array);
int			*cd_dup_int_list(int *list, int len);

// -----keys-------------------------------------------------------------------
// --keys.c
void		cd_keys(mlx_key_data_t keydata, t_game *game);
void		cd_moove_forward(t_game *game);
void		cd_moove_backward(t_game *game);
void		cd_moove_left(t_game *game);
void		cd_moove_right(t_game *game);
void		cd_jump(t_game *game);
void		cd_moove(t_game *game);
void		cd_directions_conditions(mlx_key_data_t keydata, t_game *game);
void		cd_actions_conditions(mlx_key_data_t keydata, t_game *game);
void		cd_camera_conditions(mlx_key_data_t keydata, t_game *game);
void		cd_walk(t_game *game);

// --camera.h
void		cd_right(t_game *game, float amount);
void		cd_left(t_game *game, float amount);
void		cd_up(t_game *game, float amount);
void		cd_down(t_game *game, float amount);
void		cd_camera(t_game *game);

// --wall_edition.c
void		cd_edit_wall(t_game *game, float x, float y);
void		cd_inventory_switch(double xdelta, double ydelta, t_game *game);
void		cd_mouse_input(mouse_key_t button, action_t action,
				modifier_key_t mods, t_game *game);

// -----raycast----------------------------------------------------------------
// --raycast.c
void		cd_render(t_game *game);

// --draw_walls.c
int			**cd_get_texture(t_game *game, t_ray_info *ray);
float		cd_start_dim(t_game *game);
void		cd_dim_color(t_game *game, int x, int y, float effect);
void		cd_draw_walls(t_game *game, t_ray_info *ray, int x);
void		cd_draw_c_f(t_game *game, int x);

// --draw_tiles.c
float		cd_get_p_rsqrt(t_game *game, float x2, float y2);
void		cd_draw_tiles(t_game *game, int x);

// --door_raycast.c
void		cd_render_door_slice(t_game *game);

// --utils.c
mlx_image_t	*cd_slow_raycast(t_game *game, struct timeval start_time,
				int target_fps);
void		cd_modif_res(t_game *game, int moment, int force);

// --sprites.c
void		cd_sort_sprites(t_game *game);
void		cd_render_sprites(t_game *game, int move_height);

// --sprite_list_utils.c
void		cd_add_sprite(t_game *game, float x, float y);
void		cd_remove_sprite(t_game *game, int target_i);

// -----minimap----------------------------------------------------------------
void		cd_minimap(t_game *game);

// -----gui--------------------------------------------------------------------
// --gui_setup.c
void		cd_show_block_inventory(t_game *game);

// -----main-------------------------------------------------------------------
// --error.c
void		cd_free_int_tab(int **tab);
void		cd_free_all(t_game *game);
void		error_handler(char *ERR_MSG, t_game *game, char *line);

// --img_to_int.c
void		cd_img_to_int(t_game *game, t_textures *graphic);
int			cd_create_rgba(char	*color);

#endif