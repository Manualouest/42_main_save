/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_legs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:04:12 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/22 20:58:58 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proced.h>


void	pr_move_targets(t_data *data, t_leg *leg, t_sphere *elbow, t_sphere *hand)
{
	if (sqrt(pow(hand->x - (data->vars.cos[(int)pr_clamp((leg->anchor->o * 100.) + 157 * leg->side, 0, 2 * M_PI * 100)] * leg->anchor->r + leg->anchor->x), 2)
		+ pow(hand->y - (data->vars.sin[(int)pr_clamp((leg->anchor->o * 100.) + 157 * leg->side, 0, 2 * M_PI * 100)] * leg->anchor->r + leg->anchor->y), 2)) > elbow->link_len + hand->link_len)
	{
		leg->h_x = data->vars.cos[(int)pr_clamp((leg->anchor->o * 100.) + 157 * leg->side, 0, 2 * M_PI * 100)] * (leg->anchor->r + elbow->link_len * 0.7 + hand->link_len * 0.7) + leg->anchor->x;
		leg->h_y = data->vars.sin[(int)pr_clamp((leg->anchor->o * 100.) + 157 * leg->side, 0, 2 * M_PI * 100)] * (leg->anchor->r + elbow->link_len * 0.7 + hand->link_len * 0.7) + leg->anchor->y;
		leg->h_x += data->vars.cos[(int)(hand->o * 100.)] * (hand->link_len + elbow->link_len * 0.8);
		leg->h_y += data->vars.sin[(int)(hand->o * 100.)] * (hand->link_len + elbow->link_len * 0.8);
		leg->e_x = data->vars.cos[(int)pr_clamp((leg->anchor->o * 100.) + 157 * leg->side, 0, 2 * M_PI * 100)] * (leg->anchor->r + elbow->link_len * 0.7) + leg->anchor->x;
		leg->e_y = data->vars.sin[(int)pr_clamp((leg->anchor->o * 100.) + 157 * leg->side, 0, 2 * M_PI * 100)] * (leg->anchor->r + elbow->link_len * 0.7) + leg->anchor->y;
		leg->e_x += data->vars.cos[(int)pr_clamp((elbow->o * 100.), 0, 628)] * elbow->link_len * 1.8;
		leg->e_y += data->vars.sin[(int)pr_clamp((elbow->o * 100.), 0, 628)] * elbow->link_len * 1.8;
	}
}

// void	pr_move_elbow_target(t_data *data, t_leg *leg, t_sphere *elbow)
// {
	// float	dst;

	// while (sqrt(pow(elbow->x - (data->vars.cos[(int)pr_clamp((leg->anchor->o * 100.) + 157 * leg->side, 0, 2 * M_PI * 100)] * leg->anchor->r + leg->anchor->x), 2) + pow(elbow->y - (data->vars.sin[(int)pr_clamp((leg->anchor->o * 100.) + 157 * leg->side, 0, 2 * M_PI * 100)] * leg->anchor->r + leg->anchor->y), 2)) > elbow->link_len
	// 	|| sqrt(pow(elbow->x - hand->x, 2) + pow(elbow->y - hand->y, 2)) > hand->link_len)
	// {
	// if (sqrt(pow(elbow->x - hand->x, 2) + pow(elbow->y - hand->y, 2)) > hand->link_len)
	// {
	// 	elbow->o = pr_clamp((atan2(hand->y - elbow->y, hand->x - elbow->x) - atan2(data->vars.sin[0], data->vars.cos[0])), 0, 2. * M_PI);
	// 	dst = sqrt(pow(hand->x - elbow->x, 2) + pow(hand->y - elbow->y, 2));
	// 	dst = hand->link_len / dst;
	// 	elbow->x = ((1 - dst) * hand->x + dst * elbow->x);
	// 	elbow->y = ((1 - dst) * hand->y + dst * elbow->y);
	// }
	// else if (sqrt(pow(elbow->x - (data->vars.cos[(int)pr_clamp((leg->anchor->o * 100.) + 157 * leg->side, 0, 2 * M_PI * 100)] * leg->anchor->r + leg->anchor->x), 2) + pow(elbow->y - (data->vars.sin[(int)pr_clamp((leg->anchor->o * 100.) + 157 * leg->side, 0, 2 * M_PI * 100)] * leg->anchor->r + leg->anchor->y), 2)) > elbow->link_len)
	// {
	// 	elbow->o = pr_clamp((atan2(leg->anchor->y - elbow->y, leg->anchor->x - elbow->x) - atan2(data->vars.sin[0], data->vars.cos[0])), 0, 2. * M_PI);
	// 	dst = sqrt(pow(leg->anchor->x - elbow->x, 2) + pow(leg->anchor->y - elbow->y, 2));
	// 	dst = leg->anchor->link_len / dst;
	// 	elbow->x = ((1 - dst) * leg->anchor->x + dst * elbow->x);
	// 	elbow->y = ((1 - dst) * leg->anchor->y + dst * elbow->y);
	// }
	// }
// }

void	pr_move_leg(t_data *data, t_leg *leg, t_sphere *elbow, t_sphere *hand)
{
	hand->o = pr_clamp((atan2(leg->h_y - hand->y, leg->h_x - hand->x) - atan2(data->vars.sin[0], data->vars.cos[0])), 0, 2. * M_PI);
	if (hand->x < leg->h_x - 2 || hand->x > leg->h_x + 2)
		hand->x += data->vars.cos[(int)(hand->o * 100.)] * 3.5;
	if (hand->y < leg->h_y - 2 || hand->y > leg->h_y + 2)
		hand->y += data->vars.sin[(int)(hand->o * 100.)] * 3.5;
	elbow->o = pr_clamp((atan2(leg->e_y - elbow->y, leg->e_x - elbow->x) - atan2(data->vars.sin[0], data->vars.cos[0])), 0, 2. * M_PI);
	if (elbow->x < leg->e_x - 2 || elbow->x > leg->e_x + 2)
		elbow->x += data->vars.cos[(int)(elbow->o * 100.)] * 2.5;
	if (elbow->y < leg->e_y - 2 || elbow->y > leg->e_y + 2)
		elbow->y += data->vars.sin[(int)(elbow->o * 100.)] * 2.5;

}

void	pr_draw_link(t_data * data, t_coord origin, t_sphere *target)
{
	int		i;
	float	dx;
	float	dy;
	float	x;
	float	y;

	dx = pr_clamp((atan2(target->y - origin.y, target->x - origin.x) - atan2(data->vars.sin[0], data->vars.cos[0])), 0, 2. * M_PI);
	dy = data->vars.sin[(int)(dx * 100.)];
	dx = data->vars.cos[(int)(dx * 100.)];
	x = origin.x;
	y = origin.y;
	i = 0;
	while ((floor(x) < floor(target->x) - 2 || floor(x) > floor(target->x) + 2
		|| floor(y) < floor(target->y) - 2 || floor(y) > floor(target->y) + 2)
		&& ++i < 100)
	{
		x += dx;
		y += dy;
		pr_put_thick_pixel(data->mlx.screen, (int)x, (int)y, 1, target->color);
	}
}

void	pr_draw_legs(mlx_image_t *screen, t_data *data, t_leg *leg)
{
	// int		i;
	// float	dir_x;
	// float	dir_y;
	t_coord		coord;

	leg->hand->o = leg->anchor->o;
	leg->elbow->o = leg->anchor->o;
	pr_move_targets(data, leg, leg->elbow, leg->hand);
	pr_move_leg(data, leg, leg->elbow, leg->hand);
	pr_draw_circle(screen, data, leg->elbow, 0);
	pr_draw_circle(screen, data, leg->hand, 0);
	coord.x =data->vars.cos[(int)pr_clamp((leg->anchor->o * 100.) + 157 * leg->side, 0, 2 * M_PI * 100)] * leg->anchor->r + leg->anchor->x;
	coord.y =data->vars.sin[(int)pr_clamp((leg->anchor->o * 100.) + 157 * leg->side, 0, 2 * M_PI * 100)] * leg->anchor->r + leg->anchor->y;
	pr_draw_link(data, coord, leg->elbow);
	coord.x = leg->elbow->x;
	coord.y = leg->elbow->y;
	pr_draw_link(data, coord, leg->hand);
	// i = -1;
	// dir_x = atan2(leg->anchor->y - leg->elbow->y, leg->anchor->x - leg->elbow->x);
	// dir_y = data->vars.sin[(int)(dir_x * 100.)];
	// dir_x = data->vars.cos[(int)(dir_x * 100.)];
	// while (++i < leg->elbow->link_len * 0.5)
	// {
	// 	// printf("x: %f, y: %f\n", dir_x * (i * (leg->elbow->link_len / (leg->elbow->link_len * 0.5))) + leg->elbow->x, dir_y * (i * (leg->elbow->link_len / (leg->elbow->link_len * 0.5))) + leg->elbow->y);
	// 	pr_put_thick_pixel(screen, dir_x * (i * (leg->elbow->link_len / (leg->elbow->link_len * 0.5))) + leg->elbow->x, dir_y * (i * (leg->elbow->link_len / (leg->elbow->link_len * 0.5))) + leg->elbow->y, 1, 0xFFFFFFFF);
	// }
}