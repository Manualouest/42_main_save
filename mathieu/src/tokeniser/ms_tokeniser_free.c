/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokeniser_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:20:59 by mbirou            #+#    #+#             */
/*   Updated: 2024/05/19 17:58:14 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

void	ms_pipes_free_main(t_pipes *pipes)
{
	t_pipes		*tmp_pipe;
	t_params	*tmp_params;

	while (pipes != NULL)
	{
		if (pipes->command)
		{
			free(pipes->command->cmd);
			if (pipes->command->params)
			{
				while (pipes->command->params != NULL)
				{
					free(pipes->command->params->text);
					tmp_params = pipes->command->params->next;
					free(pipes->command->params);
					pipes->command->params = tmp_params;
				}
			}
			free(pipes->command);
		}
		tmp_pipe = pipes->right;
		free(pipes);
		pipes = tmp_pipe;
	}
}
