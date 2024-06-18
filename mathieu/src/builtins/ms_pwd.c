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

int	builtin_pwd(void)
{
	char	*path;
	
	path = getcwd(NULL, 0);
	printf("%s\n", path);
	free(path);
	return (EXIT_FAILURE);
}
