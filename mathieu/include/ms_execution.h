/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execution.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:44:31 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/27 11:29:39 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_EXECUTION_H
# define MS_EXECUTION_H

void	ms_exec(t_cmd *to_exec, char **env, bool is_pipe);
void	child_exec(t_cmd *to_exec, char **env);
void	ms_exec_pipe(t_cmd *to_exec, char **env);
int		ms_exec_builtin(t_cmd *to_exec, char **env);
void	ms_child_getpath(t_cmd *cmd, char *env_path);

t_cmd	*cmd_new(char **content);
void	cmd_add_back(t_cmd **cmd, t_cmd *new);
void	cmd_clear(t_cmd **cmd, void (*del)(void **));
void	cmd_iter(t_cmd *cmd, void (*f)(t_cmd *));

int		ms_setup_pipes(t_cmd *cmd);
void	ms_exec_closefds(t_cmd *cmd);

#endif