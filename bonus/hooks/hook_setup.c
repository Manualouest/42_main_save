/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:21:19 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/28 11:23:05 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>
#include <stdio.h>
int	cd_stop_window(t_info *info)
{
	mlx_loop_end(info->mlx_info->mlx);
	return (0);
}

t_ray_info	cd_check_movement(t_info *info, t_ray_info ray_info, float angle, float max_speed)
{
	double	dx;
	double	dy;
	double	ddx;
	double	ddy;
	int		step_x;
	int		step_y;
	double	side_dx;
	double	side_dy;

	dx = cos(angle);
	dy = sin(angle);

	ddx = fabs(1 / dx);
	ddy = fabs(1 / dy);

	if (dx < 0)
	{
		step_x = -1;
		side_dx = (info->p_pos->x - ray_info.x) * ddx;
	}
	else
	{
		step_x = 1;
		side_dx = (ray_info.x + 1 - info->p_pos->x) * ddx;
	}
	if (dy < 0)
	{
		step_y = -1;
		side_dy = (info->p_pos->y - ray_info.y) * ddy;
	}
	else
	{
		step_y = 1;
		side_dy = (ray_info.y + 1 - info->p_pos->y) * ddy;
	}
	ray_info.side = 0;
	while (info->map[(int)ray_info.y][(int)ray_info.x])
	{
		if (side_dx < side_dy)
		{
			side_dx += ddx;
			ray_info.x += step_x;
			ray_info.side = 0;
		}
		else
		{
			side_dy += ddy;
			ray_info.y += step_y;
			ray_info.side = 1;
		}
		if (info->map[(int)ray_info.y][(int)ray_info.x] == '1')
		{
			if (ray_info.side == 0 && side_dx - ddx <= max_speed && side_dx - ddx > max_speed / 1.1)
				ray_info.distance = side_dx - ddx;
			else if (ray_info.side == 1 && side_dy - ddy <= max_speed && side_dy - ddy > max_speed / 1.1)
				ray_info.distance = side_dy - ddy;
			else if (side_dx - ddx > max_speed || side_dy - ddy > max_speed)
				ray_info.distance = max_speed;
			else
				ray_info.distance = 0;
			break;
		}
		if (ray_info.distance == -1 && ((ray_info.side == 0 && side_dx - ddx >= max_speed * 2.0) || (ray_info.side == 1 && side_dy - ddy >= max_speed * 2.0)))
			ray_info.distance = max_speed;
	}
	if (ray_info.distance == -1)
		ray_info.distance = 0;
	return (ray_info);
}

int	cd_check_sides(t_info *info, float angle)
{
	float		left_x;
	float		left_y;
	float		right_x;
	float		right_y;
	float		n_angle;

	n_angle = cd_basic_f_clamp(angle - M_PI * 0.1, 0, 2.0 * M_PI);
	left_x = info->p_pos->x + (cos(n_angle) * 0.2);
	left_y = info->p_pos->y + (sin(n_angle) * 0.2);
	n_angle = cd_basic_f_clamp(angle + M_PI * 0.1, 0, 2.0 * M_PI);
	right_x = info->p_pos->x + (cos(n_angle) * 0.2);
	right_y = info->p_pos->y + (sin(n_angle) * 0.2);
	if (info->map[(int)floor(left_y)][(int)floor(left_x)] == '0'
		&& info->map[(int)floor(right_y)][(int)floor(right_x)] == '0')
		return (1);
	return (0);
}

void	cd_slide_on_wall(t_info *info, float angle, int side, float max_speed)
{
	float	new_x;
	float	new_y;
	float	n_angle;

	if (side == 0 && angle > 1.05 * M_PI && angle < 1.95 * M_PI)
		n_angle = 1.5 * M_PI;
	else if (side == 0 && angle < 0.95 * M_PI && angle > 0.05 * M_PI)
		n_angle = 0.5 * M_PI;
	else if (side == 1 && angle < 1.45 * M_PI && angle > 0.55 * M_PI)
		n_angle = 1.0 * M_PI;
	else if (side == 1 && (angle > 1.55 * M_PI || angle < 0.45 * M_PI))
		n_angle = 0.0;
	else
		n_angle = angle;
	new_x = info->p_pos->x + (cos(n_angle) * max_speed);
	new_y = info->p_pos->y + (sin(n_angle) * max_speed);
	if (info->map[(int)floor(new_y)][(int)floor(new_x)] == '0')
	{
		info->p_pos->x = new_x;
		info->p_pos->y = new_y;
	}
}

void	cd_go_forward(t_info *info, float max_speed)
{
	float		n_x;
	float		n_y;
	t_ray_info	ray;

	ray.x = (int)info->p_pos->x;
	ray.y = (int)info->p_pos->y;
	ray.distance = -1;
	ray = cd_check_movement(info, ray, info->p_pos->orientation, max_speed);
	ray.distance = cd_basic_f_clamp(ray.distance, 0, max_speed * 2.0);
	n_x = info->p_pos->x + (cos(info->p_pos->orientation) * ray.distance);
	n_y = info->p_pos->y + (sin(info->p_pos->orientation) * ray.distance);
	if (info->map[(int)floor(n_y)][(int)floor(n_x)] == '0'
		&& cd_check_sides(info, info->p_pos->orientation))
	{
		info->p_pos->x = n_x;
		info->p_pos->y = n_y;
	}
	else
		cd_slide_on_wall(info, info->p_pos->orientation, ray.side, max_speed);
}

void	cd_go_backward(t_info *info, float max_speed)
{
	float		n_x;
	float		n_y;
	t_ray_info	ray;

	ray.x = (int)info->p_pos->x;
	ray.y = (int)info->p_pos->y;
	ray.distance = -1;
	ray = cd_check_movement(info, ray, cd_basic_f_clamp(
		info->p_pos->orientation - M_PI, 0, 2.0 * M_PI), max_speed);
	ray.distance = cd_basic_f_clamp(ray.distance, 0, max_speed * 2.0);
	n_x = info->p_pos->x - (cos(info->p_pos->orientation) * ray.distance);
	n_y = info->p_pos->y - (sin(info->p_pos->orientation) * ray.distance);
	if (info->map[(int)floor(n_y)][(int)floor(n_x)] == '0'
		&& cd_check_sides(info, cd_basic_f_clamp(
			info->p_pos->orientation - M_PI, 0, 2.0 * M_PI)))
	{
		info->p_pos->x = n_x;
		info->p_pos->y = n_y;
	}
	else
		cd_slide_on_wall(info, cd_basic_f_clamp(
			info->p_pos->orientation - M_PI, 0, 2.0 * M_PI),
			ray.side, max_speed);
}

void	cd_straf_left(t_info *info, float speed)
{
	float	new_x;
	float	new_y;
	float	angle;

	angle = cd_basic_f_clamp(
		info->p_pos->orientation + 0.5 * M_PI, 0, 2.0 * M_PI);
	new_x = info->p_pos->x - (cos(angle) * speed) * 2.0;
	new_y = info->p_pos->y - (sin(angle) * speed) * 2.0;
	if (info->map[(int)floor(new_y)][(int)floor(new_x)] == '0')
	{
		info->p_pos->x -= cos(angle) * speed;
		info->p_pos->y -= sin(angle) * speed;
	}
}

void	cd_straf_right(t_info *info, float speed)
{
	float	new_x;
	float	new_y;
	float	angle;

	angle = cd_basic_f_clamp(
		info->p_pos->orientation - 0.5 * M_PI, 0, 2.0 * M_PI);
	new_x = info->p_pos->x - (cos(angle) * speed) * 2.0;
	new_y = info->p_pos->y - (sin(angle) * speed) * 2.0;
	if (info->map[(int)floor(new_y)][(int)floor(new_x)] == '0')
	{
		info->p_pos->x -= cos(angle) * speed;
		info->p_pos->y -= sin(angle) * speed;
	}
}

float	cd_mouse_ups(t_info *info)
{
	int		x;
	int		y;
	float	orient;

	x = 0;
	y = 0;
	orient = 0;
	mlx_mouse_get_pos(info->mlx_info->mlx, info->mlx_info->mlx_win, &x, &y);
	if (y < info->mlx_info->w_height / 2.0)// - 50
		orient = 3.0 * ((info->mlx_info->w_height / 2.0 - (float)y) / 25.0);
	if (y > info->mlx_info->w_height / 2.0)// + 50
		orient = -3.0 * (((float)y - info->mlx_info->w_height / 2.0) / 25.0);
	mlx_mouse_move(info->mlx_info->mlx, info->mlx_info->mlx_win, x, info->mlx_info->w_height / 2.0);
	return (orient);
}

void	cd_up_down(t_info *info, float turn_speed)
{
	float	cam;

	cam = cd_mouse_ups(info);
	if ((cam > 0 || (info->keys->up && !info->keys->down && cam != -1))
		&& info->p_pos->pitch < info->mlx_info->fov
		&& info->p_pos->pitch + turn_speed < info->mlx_info->fov -
			(info->p_pos->height + 0.075) * (info->mlx_info->fov / 0.5))
		info->p_pos->pitch += turn_speed * (cam + (cam == 0));
	else if ((cam < 0 || (info->keys->down && !info->keys->up && cam != 1))
		&& info->p_pos->pitch > -info->mlx_info->fov
		&& info->p_pos->pitch - turn_speed > -info->mlx_info->fov -
			(info->p_pos->height - 0.075) * (info->mlx_info->fov / 0.5))
		info->p_pos->pitch -= turn_speed * (-cam + (cam == 0));
	// if (info->p_pos->pitch > info->mlx_info->fov -
	// 	((info->p_pos->height + 0.125) * (info->mlx_info->fov / 0.55)))
	// 	info->p_pos->pitch -= turn_speed / 2.0;
	// else if (info->p_pos->pitch < -info->mlx_info->fov -
	// 	((info->p_pos->height - 0.125) * (info->mlx_info->fov / 0.55)))
	// 	info->p_pos->pitch += turn_speed / 2.0;
	if (info->keys->rise && !info->keys->lower && info->p_pos->height < 0.40)
		info->p_pos->height += 0.01;
	else if (info->keys->lower && !info->keys->rise
		&& info->p_pos->height > -0.40)
		info->p_pos->height -= 0.01;
}

int	cd_key_pressed(int keycode, t_info *info)
{
	// printf("keycode: %d\n", keycode);
	
	if (keycode == 65307)
		cd_stop_window(info);
	if (keycode == 32)
		cd_place_block(info);
	// {
	// 	mlx_mouse_move(info->mlx_info->mlx, info->mlx_info->mlx_win,
	// 		info->mlx_info->w_width / 2.0, info->mlx_info->w_height / 2.0);
	// 	info->p_pos->height = 0;
	// }
	if (keycode == 65513)
		cd_mine_block(info);
	if (keycode == 65289)
		cd_switch_display(info, 2);
	if (keycode == 65505)
		info->keys->sprint = 1;
	if (keycode == 119)
		info->keys->forward = 1;
	if (keycode == 99)
		info->keys->minimap = 1 - (info->keys->minimap == 1);
	else if (keycode == 115)
		info->keys->backward = 1;
	else if (keycode == 97)
		info->keys->straf_left = 1;
	else if (keycode == 100)
		info->keys->straf_right = 1;
	else if (keycode == 113 || keycode == 65361)
		info->keys->left = 1;
	else if (keycode == 101 || keycode == 65363)
		info->keys->right = 1;
	else if (keycode == 65362)
		info->keys->up = 1;
	else if (keycode == 65364)
		info->keys->down = 1;
	else if (keycode == 120)
		info->keys->rise = 1;
	else if (keycode == 122)
		info->keys->lower = 1;
	return (0);
}

int	cd_key_released(int keycode, t_info *info)
{
	if (keycode == 65505)
		info->keys->sprint = 0;
	if (keycode == 119)
		info->keys->forward = 0;
	else if (keycode == 115)
		info->keys->backward = 0;
	else if (keycode == 97)
		info->keys->straf_left = 0;
	else if (keycode == 100)
		info->keys->straf_right = 0;
	else if (keycode == 113 || keycode == 65361)
		info->keys->left = 0;
	else if (keycode == 101 || keycode == 65363)
		info->keys->right = 0;
	else if (keycode == 65362)
		info->keys->up = 0;
	else if (keycode == 65364)
		info->keys->down = 0;
	else if (keycode == 120)
		info->keys->rise = 0;
	else if (keycode == 122)
		info->keys->lower = 0;
	return (0);
}

float	cd_mouse_sides(t_info *info)
{
	int		x;
	int		y;
	float	orient;

	x = 0;
	y = 0;
	orient = 0;
	mlx_mouse_get_pos(info->mlx_info->mlx, info->mlx_info->mlx_win, &x, &y);
	if (x < info->mlx_info->w_width / 2.0)// - 50
		orient = -1.5 * ((info->mlx_info->w_width / 2.0 - (float)x) / 20.0);
	if (x > info->mlx_info->w_width / 2.0)// + 50
		orient = 1.5 * (((float)x - info->mlx_info->w_width / 2.0) / 20.0);
	mlx_mouse_move(info->mlx_info->mlx, info->mlx_info->mlx_win, info->mlx_info->w_width / 2, y);
	return (orient);
}

void	cd_turn(t_info *info, float turn_speed, float orient)
{
	info->p_pos->orientation = cd_basic_f_clamp(info->p_pos->orientation +
		turn_speed * orient, 0, 2.0 * M_PI);
	if (info->p_pos->orientation == 0.0 || info->p_pos->orientation == M_PI
		|| info->p_pos->orientation == 2.0 * M_PI
		|| info->p_pos->orientation == 1.5 * M_PI
		|| info->p_pos->orientation == 0.5 * M_PI)
		info->p_pos->orientation = cd_basic_f_clamp(info->p_pos->orientation +
			0.01, 0, 2.0 * M_PI);
	// mlx_mouse_move(info->mlx_info->mlx, info->mlx_info->mlx_win,
	// 	info->mlx_info->w_width / 2.0, info->mlx_info->w_height / 2.0);
} 

int	cd_move_player(t_info *info)
{
	float	speed;
	float	turn_speed;
	float	mouse_move;

	speed = 0.1;
	turn_speed = floor(info->mlx_info->fov / 30.0 * 1000.0) / 1000.0;
	if (info->keys->forward && !info->keys->backward)
		cd_go_forward(info, speed * (float)(1 + 1 * info->keys->sprint));
	else if (info->keys->backward && !info->keys->forward)
		cd_go_backward(info, speed);
	if (info->keys->straf_left && !info->keys->straf_right)
		cd_straf_left(info, speed);
	else if (info->keys->straf_right && !info->keys->straf_left)
		cd_straf_right(info, speed);
	mouse_move = cd_mouse_sides(info);
	if ((info->keys->left && !info->keys->right) || mouse_move < 0)
		cd_turn(info, turn_speed * (-mouse_move + (mouse_move == 0)) * (1.0 + 0.5 * (float)info->keys->sprint), -1);
	else if ((info->keys->right && !info->keys->left) || mouse_move > 0)
		cd_turn(info, turn_speed * (mouse_move + (mouse_move == 0)) * (1.0 + 0.5 * (float)info->keys->sprint), 1);
	// if (info->p_pos->orientation < 0)
	// 	info->p_pos->orientation += 2.0 * M_PI;
	// if (info->p_pos->orientation > 2.0 * M_PI)
	// 	info->p_pos->orientation -= 2.0 * M_PI;
	cd_up_down(info, cd_round(info->mlx_info->fov / 20.0 * (1.0 + 0.5 * (float)info->keys->sprint), 1000));
	return (0);
}

void	cd_hook_init(t_info *info)
{
	info->mlx_info->mlx_win = mlx_new_window(info->mlx_info->mlx,
		info->mlx_info->w_width, info->mlx_info->w_height, "Cub3d");

	// mlx_key_hook(info->mlx_info->mlx_win, key_tests, info);

	mlx_mouse_move(info->mlx_info->mlx, info->mlx_info->mlx_win,
		info->mlx_info->w_width / 2.0, info->mlx_info->w_height / 2.0);

	mlx_hook(info->mlx_info->mlx_win, 2, 1L<<0, cd_key_pressed, info);
	mlx_hook(info->mlx_info->mlx_win, 3, 1L<<1, cd_key_released, info);
	mlx_mouse_hook(info->mlx_info->mlx_win, cd_mouse_hook, info);
	// mlx_loop_hook(info->mlx_info->mlx, cd_move_player, info);

	mlx_hook(info->mlx_info->mlx_win, 17, 1L<<0, cd_stop_window, info);

	mlx_loop_hook(info->mlx_info->mlx, cd_update_frame, info);
	// cd_update_frame(info);
	mlx_mouse_hide(info->mlx_info->mlx, info->mlx_info->mlx_win);
	mlx_loop(info->mlx_info->mlx);
	mlx_destroy_window(info->mlx_info->mlx, info->mlx_info->mlx_win);
}