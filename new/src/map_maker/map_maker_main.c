/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:55:42 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/02 17:59:45 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

char	**setup_clear_map(void)
{
	char	**map;

	map = ft_calloc(sizeof(char), 4);
	map[0] = ft_calloc(sizeof(char), 4);
	map[1] = ft_calloc(sizeof(char), 4);
	map[2] = ft_calloc(sizeof(char), 4);
	map[0] = ft_strdup("111");
	map[1] = ft_strdup("101");
	map[2] = ft_strdup("111");
	return (map);
}

char	*cd_map_maker(void)
{
	t_map_editor	m_edit;

	m_edit.w_width = 1280;
	m_edit.w_height = 720;
	m_edit.m_width = 3;
	m_edit.m_height = 3;
	m_edit.map = setup_clear_map();
	mlx_init(m_edit.mlx);
	mlx_new_window(m_edit.mlx, m_edit.w_width, m_edit.w_height, "Map Editor");
	mlx_key
}
