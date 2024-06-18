/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:32:54 by mscheman          #+#    #+#             */
/*   Updated: 2024/06/12 14:36:15 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

static int	check(int argc, char **argv);

int	builtin_exit(t_cmd *cmd, int argc, char **argv, char **envp)
{
	int		error_code;
	bool	should_exit;

	error_code = check(argc, argv);
	if (cmd->first->next == NULL)
		printf("exit\n");
	if (error_code == -1)
		return (EXIT_FAILURE);
	else if (error_code == 1)
		g_signal = 2;
	else if (argv[1])
		g_signal = ft_atoi(argv[1]);
	else
		g_signal = 0;
	should_exit = (cmd->first->next == NULL);
	if (cmd->next == NULL)
	{
		free_tab((void **)envp);
		ms_free_cmd(cmd->first);
	}
	if (should_exit)
		exit(g_signal);
	return (g_signal);
}

static int	check(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (EXIT_SUCCESS);
	if (argc > 2)
	{
		error_log("too many arguments");
		return (-1);
	}
	i = 0;
	while (argv[1][i])
	{
		if (ft_isdigit(argv[1][i]) != 1)
		{
			error_log("numeric argument required");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
