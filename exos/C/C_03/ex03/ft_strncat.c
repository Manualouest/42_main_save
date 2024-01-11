/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:04:00 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/22 10:13:20 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	pos2;
	unsigned int	pos;

	pos2 = 0;
	pos = 0;
	while (dest[pos] != 0)
	{
		pos ++;
	}
	while (pos2 < nb && src[pos2] != 0)
	{
		dest[pos] = src[pos2];
		pos ++;
		pos2 ++;
	}
	dest[pos] = 0;
	return (dest);
}
