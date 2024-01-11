/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 09:39:47 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/25 09:39:49 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		write(1, &str[pos], 1);
		pos ++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > -1)
	{
		ft_putchar(argv[0]);
		write(1, "\n", 1);
	}
}
