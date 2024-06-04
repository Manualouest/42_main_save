/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_handle_sounds_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:41:27 by mbirou            #+#    #+#             */
/*   Updated: 2024/04/06 15:29:20 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_include_bonus.h"

void	sl_launch_sound(char *type)
{
	char	*path;

	if (type[0] != '1' && type[0] != '2' && type[0] != '3')
		path = gnl_strlcat(SOUND_LOUD, type, 0);
	else
		path = gnl_strlcat(SOUND_LOW, type, 0);
	path = gnl_strlcat(path, ".wav &", 1);
	free(type);
	system(path);
	free(path);
}

void	sl_do_sound_6(t_gifs *gifs)
{
	if (gifs->exit_type == 6 && gifs->exit_sound_frame <= 0
		&& gifs->exit_sound_frame > -2)
	{
		gifs->exit_sound_frame = -2;
		system("paplay --volume=25000 sounds/6.wav \
			| paplay --volume=25000 sounds/7.wav &");
	}
}

void	sl_handle_exit_sound(t_gifs *gifs, t_map_info *map_info)
{
	if (map_info->mlx->width == 1500)
		return ;
	if (gifs->exit_sound_frame == -1)
		system("if [ $(ps -e |grep \"paplay\" | wc -l) -eq 1 ]; \
			then killall paplay $!; fi");
	if (gifs->exit_sound_frame <= 0 && gifs->exit_type != 6)
		sl_launch_sound(ft_itoa(gifs->exit_type));
	if (gifs->exit_type == 0 && gifs->exit_sound_frame < 0)
		gifs->exit_sound_frame = 445;
	else if (gifs->exit_type == 1 && gifs->exit_sound_frame < 0)
		gifs->exit_sound_frame = 100;
	else if (gifs->exit_type == 2 && gifs->exit_sound_frame < 0)
		gifs->exit_sound_frame = 450;
	else if (gifs->exit_type == 3 && gifs->exit_sound_frame < 0)
		gifs->exit_sound_frame = 820;
	else if ((gifs->exit_type == 4 || gifs->exit_type == 5)
		&& gifs->exit_sound_frame < 0)
		gifs->exit_sound_frame = 330;
	else
		sl_do_sound_6(gifs);
	if (gifs->exit_sound_frame > -2 && map_info->mlx->width != 1500)
		gifs->exit_sound_frame-- ;
}

void	sl_cross_close(void	*param)
{
	(void)param;
	system("if [ $(ps -e |grep \"paplay\" | wc -l) -eq 1 ]; \
		then killall paplay $!; fi");
}
