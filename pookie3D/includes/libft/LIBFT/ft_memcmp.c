/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:18:50 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/11/11 14:50:21 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		final_value;
	int		testing_value;

	i = 0;
	if (n == 0)
		return (0);
	while (n > i)
	{
		testing_value = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		if (testing_value != 0)
			break ;
		i++;
	}
	if (i == n)
		i--;
	if (((unsigned char *)s1)[i] == 0 && ((unsigned char *)s2)[i] != 0)
		return (-1);
	if (((unsigned char *)s2)[i] == 0 && ((unsigned char *)s2)[i] != 0)
		return (1);
	final_value = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
	return (final_value);
}
