/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:33:15 by mscheman          #+#    #+#             */
/*   Updated: 2024/06/12 14:34:04 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

static int	exec_pipe_builtin(t_cmd *to_exec, char **env);

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
	int	builtin_ret;

	if (!to_exec)
		return ;
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
		builtin_ret = exec_pipe_builtin(to_exec, env);
		if (builtin_ret != -1)
			exit(builtin_ret);
		execve(to_exec->args[0], to_exec->args, env);
		cmd_clear(&to_exec, free_tab);
		free_tab((void **)env);
		error_log("bozo");
		exit(EXIT_FAILURE);
	}
}

static int	exec_pipe_builtin(t_cmd *to_exec, char **env)
{
	int	ret;

	ret = ms_exec_builtin(to_exec, env);
	return (ret);
}