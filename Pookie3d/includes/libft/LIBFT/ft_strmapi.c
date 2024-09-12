/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:12:55 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/11/11 14:50:11 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*work_str;

	i = 0;
	if (!s || !f)
		return (0);
	work_str = ft_strdup((char *)s);
	if (!work_str)
		return (0);
	while (work_str[i])
	{
		work_str[i] = f(i, work_str[i]);
		i++;
	}
	return (work_str);
}
