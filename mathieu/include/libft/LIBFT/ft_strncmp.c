/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:18:32 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/11/11 14:50:11 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((i < n - 1) && (a[i] != 0 || b[i] != 0))
	{
		if (a[i] != b[i])
			break ;
		i++;
	}
	if (a[i] == b[i])
		return (0);
	if (a[i] == 0)
		return (-1 * b[i]);
	if (b[i] == 0)
		return (a[i]);
	return (a[i] - b[i]);
}
