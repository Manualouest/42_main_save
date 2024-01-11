/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 09:44:29 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/25 09:44:30 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
	{
		len ++;
	}
	return (len);
}

int	main(int argc, char **argv)
{
	int	pos;

	pos = 1;
	if (argc > 1)
	{
		while (argc > pos)
		{
			write(1, argv[pos], ft_strlen(argv[pos]));
			write(1, "\n", 1);
			pos ++;
		}
	}
	return (0);
}
