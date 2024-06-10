/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:30:44 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/18 18:30:44 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

t_cmd	*cmd_new(char **content)
{
	t_cmd	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (0);
	node->fd_in = STDIN_FILENO;
	node->fd_out = STDOUT_FILENO;
	node->args = content;
	node->next = 0;
	return (node);
}

void	cmd_add_back(t_cmd **cmd, t_cmd *new)
{
	if ((*cmd) == NULL)
	{
		(*cmd) = new;
		return ;
	}
	if (new == NULL)
		return ;
	if ((*cmd)->next == NULL)
	{
		(*cmd)->next = new;
		return ;
	}
	cmd_add_back(&(*cmd)->next, new);
}

void	cmd_clear(t_cmd **cmd, void (*del)(void **))
{
	if (!cmd || !(*cmd) || !del)
		return ;
	if ((*cmd)->next)
		cmd_clear((&(*cmd)->next), del);
	del((void **)(*cmd)->args);
	free(*cmd);
	*cmd = NULL;
}

void	cmd_iter(t_cmd *cmd, void (*f)(t_cmd *))
{
	if (!cmd)
		return ;
	f(cmd);
	cmd_iter(cmd->next, f);
}

