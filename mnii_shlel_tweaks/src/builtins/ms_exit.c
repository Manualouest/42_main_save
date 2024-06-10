/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:32:54 by mscheman          #+#    #+#             */
/*   Updated: 2024/06/10 18:05:24 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

static int	check(int argc, char **argv);

int	builtin_exit(t_cmd *cmd, int argc, char **argv, char **envp)
{
	int	error_code;

	error_code = check(argc, argv);
	printf("exit\n");
	if (error_code == -1)
		return (EXIT_FAILURE);
	else if (error_code == 1)
		g_signal = 2;
	else if (argv[1])
		g_signal = ft_atoi(argv[1]);
	else
		g_signal = 0;
	// free_tab((void **)argv);
	free_tab((void **)envp);
	ms_free_cmd(cmd);
	exit(g_signal);
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
