/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:23:49 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/28 19:23:49 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

char	*envp_find_similar(char **envp, char *to_find)
{
	int	i;
	int	len;
	int	cmp;

	i = 0;
	len = ft_strfind(to_find, '+');
	if (len == -1)
		len = ft_strfind(to_find, '=');
	if (len == -1)
		len = ft_strlen(to_find);
	while (envp[i])
	{
		cmp = ft_strncmp(envp[i], to_find, len);
		if (cmp < 0)
			cmp = -cmp;
//		printf("ft_strncmp(%s, %s, %d) = %d (%c)\n", envp[i], to_find, len, cmp, cmp);
		if (cmp == '=' || cmp == 0)
			return (envp[i]);
		i++;
	}
//	printf("\n");
	return (NULL);
}

void	export_format_str(char *str)
{
	int	len;

	if ((ft_strfind(str, '+') == -1))
		return ;
	len = ft_strlen(str);
	str[ft_strfind(str, '+')] = 0;
	ft_strlcat(str, &str[ft_strlen(str) + 1], len);
}
