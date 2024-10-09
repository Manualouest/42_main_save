/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:54:56 by mbirou            #+#    #+#             */
/*   Updated: 2024/10/09 19:23:17 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		front;
	int		back;
	char	*trim;

	front = 0;
	if (!s1)
		return (NULL);
	back = ft_strlen((char *)s1) - 1;
	while (s1[front] != 0 && ft_strchr(set, s1[front]) != NULL)
		front ++;
	while (back > front && ft_strrchr(set, s1[back]) != NULL)
		back --;
	trim = ft_substr(s1, front, back - front + 1);
	if (!trim)
		return (NULL);
	return (trim);
}
