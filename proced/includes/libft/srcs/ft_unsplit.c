/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:57:32 by mhaouas           #+#    #+#             */
/*   Updated: 2024/04/05 16:10:40 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*free_join(char *str, char *str2)
{
	char	*tmp;

	tmp = ft_strjoin(str, str2);
	free(str);
	return (tmp);
}

char	*ft_unsplit(char **tab_to_unsplit, char sep)
{
	int		i;
	char	*tmp;
	char	s_sep[2];

	i = 1;
	s_sep[0] = sep;
	s_sep[1] = 0;
	if (!tab_to_unsplit || !sep || !*tab_to_unsplit)
		return (NULL);
	tmp = ft_strdup(tab_to_unsplit[0]);
	while (tab_to_unsplit[i])
	{
		tmp = free_join(tmp, s_sep);
		tmp = free_join(tmp, tab_to_unsplit[i]);
		i++;
	}
	return (tmp);
}
