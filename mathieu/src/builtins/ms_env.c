/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:00:59 by mscheman          #+#    #+#             */
/*   Updated: 2024/06/10 17:32:44 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

int	builtin_env(t_cmd *cmd, char **envp)
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
		ft_putstr_fd(envp[i], cmd->fd_out);
		ft_putstr_fd("\n", cmd->fd_out);
		i++;
	}
	return (EXIT_SUCCESS);
}
