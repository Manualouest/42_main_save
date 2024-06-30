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

static int	exec_pipe_builtin(t_cmd *to_exec, char ***env);

void	ms_exec(t_cmd *to_exec, char ***env, bool is_pipe)
{
	int		status;

	signal(SIGINT, SIG_IGN);
	if (is_pipe)
	{
		ms_exec_pipe(to_exec, env);
		signal(SIGINT, ms_sig_handler);
		return ;
	}
	if (ms_exec_builtin(to_exec, env) != -1)
		return ;
	child_exec(to_exec, env);
	ms_exec_closefds(to_exec);
	waitpid(to_exec->pid, &status, 0);
	if (WIFEXITED(status))
		g_signal = WEXITSTATUS(status);
	signal(SIGINT, ms_sig_handler);
}

void	child_exec(t_cmd *to_exec, char ***env)
{
	if (!to_exec)
		return ;
	to_exec->pid = fork();
	if (to_exec->pid < -1)
		error_log("fork failed", '\n');
	if (to_exec->pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (dup2(to_exec->fd_in, STDIN_FILENO) == -1)
			ms_dup2_quit(to_exec, *env);
		if (dup2(to_exec->fd_out, STDOUT_FILENO) == -1)
			ms_dup2_quit(to_exec, *env);
		ms_exec_closefds(to_exec->first);
		rl_clear_history();
		if (exec_pipe_builtin(to_exec, env) != -1)
			exit(g_signal);
		ms_child_getpath(to_exec, envp_find(*env, "PATH"));
		execve(to_exec->args[0], to_exec->args, *env);
		ms_execve_quit(to_exec, *env);
	}
}

static int	exec_pipe_builtin(t_cmd *to_exec, char ***env)
{
	int	ret;

	ret = ms_exec_builtin(to_exec, env);
	if (ret != -1)
	{
		g_signal = ret;
		ms_exec_closefds(to_exec->first);
		ms_exec_unleak(to_exec, (*env));
	}
	return (ret);
}
