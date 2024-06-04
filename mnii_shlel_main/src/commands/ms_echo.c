/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:33:36 by mscheman          #+#    #+#             */
/*   Updated: 2024/04/26 21:33:36 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

static bool	print_str(char *str);

void	ms_echo(char *params[])
{
	int		i;
	t_bool	with_endl;

	i = 0;
	with_endl = true;
	if (!params || !*params)
		return ;
	while (params[i])
		with_endl *= print_str(params[i++]);
	if (with_endl)
		printf("\n");
}

static bool	print_str(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (strcmp(str, "-n") == 0)
		return (false);
	printf("%s ", str);
	return (true);
}
