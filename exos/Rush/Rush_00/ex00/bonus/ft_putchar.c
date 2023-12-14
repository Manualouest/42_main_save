/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:01:28 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/19 13:18:50 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int current_char)
{
	if (current_char == 0)
		write(1, "A", 1);
	if (current_char == 1)
		write(1, "B", 1);
	if (current_char == 2)
		write(1, " ", 1);
	if (current_char == 3)
		write(1, "C", 1);
	if (current_char == 4)
		write(1, "-", 1);
	if (current_char == 5)
		write(1, "o", 1);
	if (current_char == 6)
		write(1, "\n", 1);
	if (current_char == 7)
		write(1, "|", 1);
	if (current_char == 8)
		write(1, "/", 1);
	if (current_char == 9)
		write(1, "*", 1);
	if (current_char == 10)
		write(1, "\\", 1);
}
