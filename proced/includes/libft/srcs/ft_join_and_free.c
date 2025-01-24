/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrech <malbrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:57:55 by mhaouas           #+#    #+#             */
/*   Updated: 2024/05/01 19:29:42 by malbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*join_and_free(char *s1, char *s2, int f_s1, int f_s2)
{
	char	*buff;

	if (!s1)
	{
		f_s1 = 0;
		s1 = "";
	}
	if (!s2)
	{
		f_s2 = 0;
		s2 = "";
	}
	buff = ft_strjoin(s1, s2);
	if (f_s1)
		free(s1);
	if (f_s2)
		free(s2);
	return (buff);
}
