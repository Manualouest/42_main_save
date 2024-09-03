/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:27:38 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/03 14:35:36 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_mlx
{
	int	tp;
}		t_mlx;

typedef struct s_keys
{
	int	tp;
}		t_keys;

typedef struct	s_textures
{
	int	tp;
}		t_textures;


typedef struct	s_struct_link
{
	int			error;
	t_mlx		t_mlx;
	t_keys		keys;
	t_textures	t_texts;
}				t_s_link;

# include <stdio.h>

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include <unistd.h>

# include <mlx.h>
# include "libft.h"
# include "get_next_line_bonus.h"

// -----map_maker-----
// map_maker_main.c
char	*cd_map_maker(void);


#endif