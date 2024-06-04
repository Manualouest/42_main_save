/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_initfds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:19:53 by mscheman          #+#    #+#             */
/*   Updated: 2024/06/01 17:03:38 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

void	ms_exec_initfds(t_cmd *cmd)
{
	int	pipes_fd[2];

	if (cmd->next == NULL)
		return ;
	pipe(pipes_fd);
	printf("Opened pipe with entry %d and exit %d\n", pipes_fd[0], pipes_fd[1]);
	cmd->fd_out = pipes_fd[1];
	cmd->next->fd_in = pipes_fd[0];
}

void	ms_exec_redirectupdate(t_cmd *cmd, int infile, int outfile)
{
	cmd->fd_in = infile;
	while (cmd->next != NULL)
		cmd = cmd->next;
	cmd->fd_out = outfile;
}

void	ms_exec_closefds(t_cmd *cmd)
{
	while (cmd != NULL)
	{
		close(cmd->fd_in);
		close(cmd->fd_out);
		cmd = cmd->next;
	}
}
