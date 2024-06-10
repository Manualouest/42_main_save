/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd.ct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:07:15 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/01 17:07:15 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

int	builtin_pwd(void)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (path == NULL)
	{
		i++;
		path = getcwd(NULL, i);
	}
	printf("%s\n", path);
	free(path);
	return (EXIT_FAILURE);
}
