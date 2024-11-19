/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:28:27 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/16 12:28:34 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	tab_len(char	**tab)
{
	int	i;

	i = 0;
	while (tab && tab[i] != NULL)
		i ++;
	return (i);
}

char	**add_new_line(char *line, char **tab)
{
	char		**new_tab;
	int			len_tab;
	int			i;

	len_tab = tab_len(tab);
	new_tab = malloc(sizeof(*new_tab) * (len_tab + 2));
	new_tab[len_tab + 1] = NULL;
	new_tab[len_tab] = line;
	i = -1;
	while (tab && ++i < len_tab)
		new_tab[i] = tab[i];
	if (tab)
		free(tab);
	return (new_tab);
}

float	*cd_add_flst(float *list, float new)
{
	int		i;
	float	*n_list;

	i = -1;
	while (list && list[++i != -1])
		;
	n_list = malloc(sizeof(*n_list) * (i + 2));
	n_list[i] = new;
	n_list[i + 1] = -1;
	while (--i >= 0)
		n_list[i] = list[i];
	if (list)
		free(list);
	return (n_list);
}
