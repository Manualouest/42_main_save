/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:54:15 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/22 10:03:37 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	pos;
	int	pos2;

	pos2 = 0;
	pos = 0;
	while (dest[pos] != 0)
	{
		pos ++;
	}
	while (src[pos2] != 0)
	{
		dest[pos] = src[pos2];
		pos ++;
		pos2 ++;
	}
	dest[pos] = 0;
	return (dest);
}
