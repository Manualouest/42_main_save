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
	bool	without_nl;
	int		cmp;
	int		i;

	if (!argv || !argv[1])
	{
		printf("\n");
		return (EXIT_SUCCESS);
	}
	i = 1;
	cmp = ft_strncmp(argv[i], "-n", ft_strlen(argv[i]) + 1);
	without_nl = (cmp == 0 || cmp == 'n');
	while (argv[i] && (cmp == 0 || cmp == 'n'))
	{
		cmp = ft_strncmp(argv[i], "-n", ft_strlen(argv[i]));
		i++;
	}
	i = i - (i > 1);
	while (argv[i])
	{
		printf("%s", argv[i]);
		i++;
		if (argv[i])
			printf(" ");
	}
	if (!without_nl)
		printf("\n");
	return (EXIT_SUCCESS);
}
