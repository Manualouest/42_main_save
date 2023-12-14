/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:25:31 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/22 10:34:01 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	pos;
	unsigned int	pos2;

	pos = 0;
	pos2 = 0;
	while (dest[pos] != 0 && pos < size)
		pos ++;
	while (src[pos2] != 0 && pos2 + pos < size - 1)
	{
		dest[pos + pos2] = src[pos2];
		pos2 ++;
	}
	if (src[pos2] != 0)
		return (pos + size);
	dest[pos + pos2] = 0;
	return (pos + pos2);
}
