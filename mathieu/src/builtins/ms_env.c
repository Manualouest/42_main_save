/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:00:59 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/01 17:00:59 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

int	builtin_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strctn(envp[i], "="))
		{
			i++;
			continue ;
		}
			printf("%s\n", envp[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
