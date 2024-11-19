/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:03:21 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/16 15:09:07 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

void	*cd_free_tab_img(mlx_image_t **tab, t_map_editor *m_edit, int full_free)
{
	int	i;

	i = 0;
	while (tab && tab[i] != NULL)
	{
		mlx_delete_image(m_edit->mlx, tab[i]);
		i ++;
	}
	if (full_free)
		free(tab);
	return (NULL);
}

int	cd_tab_len(mlx_image_t	**tab)
{
	int	i;

	i = 0;
	while (tab && tab[i] != NULL)
		i ++;
	return (i);
}

mlx_image_t	**cd_append_img(mlx_image_t	**tab, mlx_image_t	*elem)
{
	mlx_image_t	**new_tab;
	int			len_tab;
	int			i;

	len_tab = cd_tab_len(tab);
	new_tab = malloc(sizeof(*new_tab) * (len_tab + 2));
	new_tab[len_tab + 1] = NULL;
	new_tab[len_tab] = elem;
	i = -1;
	while (tab && ++i < len_tab)
		new_tab[i] = tab[i];
	if (tab)
		free(tab);
	return (new_tab);
}

void	cd_add_text(t_map_editor *m_edit, char *text, int x, int y)
{
	(&m_edit->m_info)->text = cd_append_img((&m_edit->m_info)->text,
			mlx_put_string(m_edit->mlx, text, x, y));
}

void	cd_resizer(mlx_image_t *img, int width, int height)
{
	int	new_width;
	int	new_height;

	new_width = img->width + width;
	new_height = img->height + height;
	mlx_resize_image(img, new_width, new_height);
}
