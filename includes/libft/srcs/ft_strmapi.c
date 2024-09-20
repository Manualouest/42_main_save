/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:33:42 by mhaouas           #+#    #+#             */
/*   Updated: 2024/04/05 16:10:40 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*buff;

	i = 0;
	if (!s)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!buff)
		return (NULL);
	while (s[i])
	{
		buff[i] = f(i, s[i]);
		i++;
	}
	buff[i] = 0;
	return (buff);
}
