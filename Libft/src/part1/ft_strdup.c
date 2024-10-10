/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:05:23 by mbirou            #+#    #+#             */
/*   Updated: 2024/10/10 19:42:43 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = -1;
	while (s[++i])
		;
	dup = malloc(sizeof(*dup) * (i + 1));
	if (!dup)
		return (NULL);
	i ++;
	while (--i >= 0)
		dup[i] = s[i];
	return (dup);
}
