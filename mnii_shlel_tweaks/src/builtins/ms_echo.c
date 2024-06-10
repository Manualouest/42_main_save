/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:33:36 by mscheman          #+#    #+#             */
/*   Updated: 2024/06/10 18:15:13 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

int	builtin_echo(char **argv)
{
	bool	print_endl;
	int		i;

	if (!argv || !argv[1])
	{
		printf("\n");
		return (EXIT_SUCCESS);
	}
	print_endl = (ft_strncmp(argv[1], "-n", 2) == 0);
	i = print_endl;
	while (true)
	{
		i++;
		if (!argv[i])
			break ;
		printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
	}
	if (!print_endl)
		printf("\n");
	return (EXIT_SUCCESS);
}
