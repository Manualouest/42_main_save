/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:33:36 by mscheman          #+#    #+#             */
/*   Updated: 2024/06/10 18:15:13 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

int	builtin_echo(t_cmd *cmd)
{
	char	**args;
	bool	without_nl;
	int		cmp;
	int		i;

	args = cmd->args;
	if (!args || !args[1])
	{
		ft_putstr_fd("\n", cmd->fd_out);
		return (EXIT_SUCCESS);
	}
	i = 1;
	cmp = ft_strncmp(args[i], "-n", ft_strlen(args[i]) + 1);
	without_nl = (cmp == 0 || cmp == 'n');
	while (args[i] && (cmp == 0 || cmp == 'n'))
	{
		cmp = ft_strncmp(args[i], "-n", ft_strlen(args[i]));
		i++;
	}
	i = i - (i > 1);
	while (args[i])
	{
		ft_putstr_fd(args[i], cmd->fd_out);
		i++;
		if (args[i])
			ft_putstr_fd(" ", cmd->fd_out);
	}
	if (!without_nl)
		ft_putstr_fd("\n", cmd->fd_out);
	return (EXIT_SUCCESS);
}
