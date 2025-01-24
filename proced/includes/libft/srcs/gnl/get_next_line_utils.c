/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:10:08 by mhaouas           #+#    #+#             */
/*   Updated: 2024/04/05 16:11:10 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

int	is_new_line(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\n' && buff[i])
	{
		i++;
	}
	if (buff[i] == '\n')
		return (i + 1);
	return (-1);
}

char	*ft_strcat(char *s1, char *s2, char *array)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		array[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		array[i + j] = s2[j];
		j++;
	}
	array[j + i] = '\0';
	return (array);
}
