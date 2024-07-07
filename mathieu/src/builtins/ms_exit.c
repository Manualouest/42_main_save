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
static int	atoi_exit(char *nptr);

int	builtin_exit(t_cmd *cmd, int argc, char **argv, char **envp)
{
	int		error_code;
	bool	in_child;

	error_code = check(argc, argv);
	if (error_code == -1)
		return (EXIT_FAILURE);
	in_child = (cmd->first->next != NULL);
	if (!in_child)
		ft_putstr_fd("exit\n", cmd->fd_out);
	if (error_code == 1)
		g_signal = 2;
	else if (argv[1])
		g_signal = (atoi_exit(argv[1]));
	else
		g_signal = 0;
	if (g_signal == -1)
	{
		g_signal = 2;
		error_log("numeric argument required", '\n');
	}
	if (cmd && cmd->next == NULL)
		ms_exec_unleak(cmd, envp);
	if (!in_child)
		exit(g_signal);
	return (g_signal);
}

static int	check(int argc, char **argv)
{
	int	i;
	int	start;

	if (argc == 1)
		return (EXIT_SUCCESS);
	i = 0;
	while (ft_isspace(argv[1][i]))
		i++;
	start = i;
	while (argv[1][i])
	{
		if (ft_isdigit(argv[1][i]) != 1
			&& !(i == start && (argv[1][i] == '+' || argv[1][i] == '-')))
		{
			error_log("numeric argument required", '\n');
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (argc > 2 && atoi_exit(argv[1]) != -1)
	{
		error_log("too many arguments", '\n');
		return (-1);
	}
	return (EXIT_SUCCESS);
}

static int	atoi_exit(char *nptr)
{
	int			i;
	int			sign;
	__int128_t	num;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	sign = 1;
	if (nptr[i] == '-')
		sign = sign * -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	num = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = nptr[i] - '0' + num * 10;
		if ((num > LLONG_MAX && sign > 0)
			|| ((num > (__int128_t)LLONG_MAX + 1) && sign < 0))
			return (-1);
		i++;
	}
	return (int)(sign * (num % 256));
}
