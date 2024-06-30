/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:05:06 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/01 17:05:06 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

static void	tab_remove(char ***tab, char *to_remove);

int	builtin_unset(char **argv, char ***envp)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		tab_remove(envp, argv[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}

static void	tab_remove(char ***tab, char *to_remove)
{
	int		i;
	int		j;
	char	*search;
	char	**new;

	i = 0;
	j = 0;
	search = envp_find((*tab), to_remove);
	if (!search)
		return ;
	new = malloc(sizeof(char *) * tablen(*tab));
	while ((*tab)[i])
	{
		if ((*tab)[i] == search)
			i++;
		new[j] = ft_strdup((*tab)[i]);
		i++;
		j++;
	}
	new[j] = NULL;
	free_tab((void **)(*tab));
	(*tab) = new;
}