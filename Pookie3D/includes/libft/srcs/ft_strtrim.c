/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:04:32 by mhaouas           #+#    #+#             */
/*   Updated: 2024/04/05 16:10:40 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	front_check(char const *s1, char const *set)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (set[i])
	{
		if (set[i] == s1[c])
		{
			c++;
			i = 0;
		}
		else
			i++;
	}
	return (c);
}

static int	back_check(char const *s1, char const *set)
{
	int	i;
	int	c;

	i = 0;
	c = ft_strlen(s1) - 1;
	while (set[i])
	{
		if (set[i] == s1[c])
		{
			c--;
			i = 0;
		}
		else
			i++;
	}
	return (c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	new_size;
	int		ind_front;
	int		ind_back;
	char	*buff;

	if ((!s1) || (!set))
		return (NULL);
	ind_front = front_check(s1, set);
	ind_back = back_check(s1, set);
	new_size = (ind_back - ind_front) + 1;
	if (ft_strlen(s1 + ind_front) == 0)
	{
		buff = (char *)malloc(sizeof(char));
		buff[0] = 0;
	}
	else
		buff = ft_substr(s1, ind_front, new_size);
	if (!buff)
		return (NULL);
	return (buff);
}
