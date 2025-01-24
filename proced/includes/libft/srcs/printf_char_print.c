/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:15:58 by mhaouas           #+#    #+#             */
/*   Updated: 2024/05/05 17:25:34 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_cputstr(int fd, char *str)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	if (!str)
	{
		count = write(fd, "(null)", 6);
		return (count);
	}
	while (str[i])
	{
		count += write(fd, str + i, 1);
		i++;
	}
	return (count);
}

int	ft_cputchar(int fd, char c)
{
	int	count;

	count = 0;
	count += write(fd, &c, 1);
	return (count);
}
