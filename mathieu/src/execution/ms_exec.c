/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:33:15 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/28 15:10:50 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

void	ms_exec(t_cmd *to_exec, char **env, bool is_pipe)
{
	int	status;

	if (is_pipe)
	{
		ms_exec_pipe(to_exec, tab_clone(env));
		return ;
	}
	if (ms_exec_builtin(to_exec, env) != -1)
		return ;
	child_exec(to_exec, env);
	waitpid(-1, &status, 0);
	if (WIFEXITED(status))
		g_signal = WEXITSTATUS(status);
}

void	child_exec(t_cmd *to_exec, char **env)
{
	to_exec->pid = fork();
	if (to_exec->pid < -1)
		error_log("fork failed");
	if (to_exec->pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		ms_child_getpath(to_exec, envp_find(env, "PATH"));
		if (dup2(to_exec->fd_in , STDIN_FILENO) == -1)
			error_log("fd_in");
		if (dup2(to_exec->fd_out , STDOUT_FILENO) == -1)
			error_log("fd_out");
		ms_exec_closefds(to_exec);
		execve(to_exec->args[0], to_exec->args, env);
		cmd_clear(&to_exec, free_tab);
		free_tab((void **)env);
		error_log("bozo");
		exit(EXIT_FAILURE);
	}
}
