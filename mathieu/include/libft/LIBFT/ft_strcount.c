/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:07:44 by mscheman          #+#    #+#             */
/*   Updated: 2024/03/13 11:39:58 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcount(char *str, char c)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (str[i])
		found += (str[i++] == c);
	return (found);
}
