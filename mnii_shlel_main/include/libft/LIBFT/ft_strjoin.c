/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:55:08 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2024/03/12 01:15:54 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_three_strcat(char *dest, char const *s1, char const *s2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*work_str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	work_str = malloc(sizeof(char) * len + 2);
	if (!work_str)
		return (NULL);
	ft_three_strcat(work_str, s1, s2);
	work_str[len] = 0;
	return (work_str);
}

static void	ft_three_strcat(char *dest, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
}
