/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrech <malbrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:14:56 by mhaouas           #+#    #+#             */
/*   Updated: 2024/05/01 19:26:58 by malbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_multi_join(int n_to_free, char *join_to, ...)
{
	va_list	va_to_join;
	char	*tmp;
	char	*final;
	int		i;

	i = 1;
	va_start(va_to_join, join_to);
	final = ft_strdup(join_to);
	if (!final)
		return (NULL);
	while (i < n_to_free)
	{
		tmp = va_arg(va_to_join, char *);
		if (tmp)
			final = join_and_free(final, tmp, 1, 0);
		if (!final)
			return (NULL);
		i++;
	}
	va_end(va_to_join);
	return (final);
}
