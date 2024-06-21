/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_heredoc_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 22:57:30 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/21 15:18:03 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

int	ms_is_last_heredoc(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		if (!ft_strncmp(cmd->args[i], "<<", 2) && ft_strlen(cmd->args[i]) == 2)
			return (0);
	}
	return (1);
}

char	*ms_launch_heredoc(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (cmd->args[++i])
	{
		if (!ft_strncmp(cmd->args[i], "<<", 2) && ft_strlen(cmd->args[i]) == 2)
		{
			if (cmd->args[i + 1])
			{
				if (ms_is_last_heredoc(cmd->args[i + 1]))
					ms_do_heredoc(cmd->args[i + 1]);
			}
		}
	}
	return (NULL);
}
