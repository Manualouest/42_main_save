/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:19:32 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/22 10:25:10 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	pos;
	int	pos2;

	pos = 0;
	pos2 = 0;
	if (to_find[pos2] == 0)
		return (&str[pos]);
	while (str[pos] != 0)
	{
		if (str[pos] == to_find[pos2])
		{
			pos2 = 0;
			while (str[pos + pos2] == to_find[pos2]
				&& to_find[pos2] != 0)
			{
				pos2 ++;
			}
			if (to_find[pos2] == 0)
				return (&str[pos]);
		}
		pos ++;
	}
	return (0);
}
