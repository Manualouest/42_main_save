/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:18:13 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/22 09:43:46 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	pos;

	pos = 0;
	while (s1[pos] != 0 && s2[pos] != 0)
	{
		if (s1[pos] == s2[pos])
			pos++;
		else if (s1[pos] > s2[pos])
			return (1);
		else if (s1[pos] < s2[pos])
			return (-1);
	}
	if (s1[pos] != 0 && s2[pos] == 0)
		return (1);
	else if (s1[pos] == 0 && s2[pos] != 0)
		return (-1);
	else
		return (0);
}
