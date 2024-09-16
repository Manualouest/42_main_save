/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:23:57 by mbirou            #+#    #+#             */
/*   Updated: 2024/09/16 15:22:02 by mbirou           ###   ########.fr       */
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
		new_str[i] = src[i];
	if (src)
		free(src);
	return (new_str);
}

void	*cd_free_tab(char	**tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}

char	*cd_realloc(char *src, char *new, int need_dup)
{
	free(src);
	if (need_dup)
		return (ft_strdup(new));
	return (new);
}

int	cd_check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd != -1)
		close (fd);
	if (fd == -1 && errno != EACCES)
		return (0);
	if (errno == EACCES)
		return (-1);
	return (1);
}

int	cd_check_input(t_map_info *m_info, char *input, int step)
{
	int		i;
	char	**txt;
	char	**map_size;

	i = -1;
	txt = ft_split(input, ',');
	if (step == 9)
		map_size = ft_split(m_info->map_size, ',');
	while (txt && ++i <= 2 - (step == 8) && txt[i])
	{
		if (step != 9 && (ft_atoi(txt[i]) < 0
				|| ft_atoi(txt[i]) > 255 * (1 + 1 * (step == 8))
				|| (ft_atoi(txt[i]) == 0
					&& (ft_strlen(txt[i]) != 1 || txt[i][0] != '0'))))
			break ;
		if (step == 9 && ((i != 2 && (ft_atoi(txt[i]) < 1
						|| ft_atoi(txt[i]) >= ft_atoi(map_size[i]) - 1))
				|| (i == 2 && (ft_strlen(txt[i]) != 1 || (txt[i][0] != 'n'
						&& txt[i][0] != 's' && txt[i][0] != 'w' && txt[i][0] != 'e')))))
			break ;
	}
	cd_free_tab(txt);
	if (step == 9)
		cd_free_tab(map_size);
	return (i == 3 - (step == 8));
}
