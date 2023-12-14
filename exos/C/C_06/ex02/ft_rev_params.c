/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:09:36 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/28 14:09:38 by mbirou           ###   ########.fr       */
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
	if (argc > 1)
	{
		while (argc > 1)
		{
			write(1, argv[argc - 1], ft_strlen(argv[argc - 1]));
			write(1, "\n", 1);
			argc --;
		}
	}
	return (0);
}
