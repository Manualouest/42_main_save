/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_setup_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:30:40 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/28 17:45:23 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

char	*cd_re_malloc(char *src, char *new)
{
	if (src)
		free(src);
	return (new);
}

int	cd_tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i ++;
	return (i);
}

void	cd_free_tab_content(char **tab)
{
	int i;

	i = -1;
	while (tab && tab[++i])
		free(tab[i]);
}

char	**cd_tab_append(char **src, char *elem)
{
	char	**dest;
	int		i;

	i = 0;
	dest = ft_calloc(sizeof(char *), cd_tab_len(src) + 2);
	while (src && src[i])
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = elem;
	if (src)
		free(src);
	return (dest);
}
