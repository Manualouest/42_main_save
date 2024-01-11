/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:13:51 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/21 16:14:37 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned char a)
{
	char	*table;

	table = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &table[a / 16], 1);
	write(1, &table[a % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != 0)
	{
		if (str[pos] < 32)
		{
			print_hex((unsigned char)str[pos]);
		}
		else
			write(1, &str[pos], 1);
		pos++;
	}
	print_hex((unsigned char)str[pos]);
}
