/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrech <malbrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:16:56 by malbrech          #+#    #+#             */
/*   Updated: 2024/10/02 21:44:34 by malbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	format_d_tab(char *paths[7])
{
	int	i;
	int	ii;

	i = 0;
	while (paths[i])
	{
		ii = 0;
		while (paths[i][ii])
		{
			skip_direction(paths[i], &ii);
			if (paths[i][ii] == ' ' || paths[i][ii] == '\t')
				ii++;
			else
			{
				paths[i] = format_d_line(paths[i], &ii);
				break ;
			}
		}
		i++;
	}
}

void	skip_direction(char *line, int *ii)
{
	if (line[*ii] == 'N' && line[*ii + 1] == 'O')
		*ii += 2;
	if (line[*ii] == 'S' && line[*ii + 1] == 'O')
		*ii += 2;
	if (line[*ii] == 'W' && line[*ii + 1] == 'E')
		*ii += 2;
	if (line[*ii] == 'E' && line[*ii + 1] == 'A')
		*ii += 2;
	if (line[*ii] == 'C')
		*ii += 1;
	if (line[*ii] == 'F')
		*ii += 1;
}

char	*format_d_line(char *line, int *ii)
{
	int		iii;
	int		i;
	int		len;
	char	*new;

	len = 0;
	i = *ii;
	while (line[*ii] != ' ' && line[*ii] != '\t' && line[*ii] != '\n' && line[*ii])
	{
		len += 1;
		*ii += 1;
	}
	new = malloc(len + 1 * sizeof(char));
	iii = 0;
	while (iii < len)
	{
		new[iii] = line[i];
		iii++;
		i++;
	}
	new[iii] = '\0';
	free(line);
	return (new);
}
