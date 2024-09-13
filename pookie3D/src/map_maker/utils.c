/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:23:57 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/13 20:44:51 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_maker.h>

char	*cd_append_char(char *src, char c)
{
	char	*new_str;
	int		len_src;
	int		i;

	len_src = ft_strlen(src);
	new_str = malloc(sizeof(*new_str) * (len_src + 2));
	new_str[len_src + 1] = 0;
	new_str[len_src] = c;
	i = -1;
	while (src && src[++i])
		new_str[i] =src[i];
	if (src)
		free(src);
	return (new_str);
}

void	*cd_free_tab(mlx_image_t **tab, t_map_editor *m_edit, int full_free)
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

char	*cd_realloc(char *src, char *new, int need_dup)
{
	free(src);
	if (need_dup)
		return (ft_strdup(new));
	return (new);
}
