/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd.ct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:07:15 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/01 17:07:15 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

int	builtin_pwd(t_cmd *cmd)
{
	char	*path;
	
	path = getcwd(NULL, 0);
	ft_putstr_fd(path, cmd->fd_out);
	ft_putstr_fd("\n", cmd->fd_out);
	free(path);
	return (EXIT_SUCCESS);
}
