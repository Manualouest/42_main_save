/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:50:08 by mbirou            #+#    #+#             */
/*   Updated: 2024/05/19 19:50:52 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

void	ms_free_cmd(t_cmd *cmd)
{
	int		i;
	t_cmd	*tp_cmd;

	while (cmd != NULL)
	{
		i = -1;
		while (cmd->args[++i] != 0)
			free(cmd->args[i]);
		free(cmd->args[i]);
		free(cmd->args);
		tp_cmd = cmd->next;
		free(cmd);
		cmd = tp_cmd;
	}
}
