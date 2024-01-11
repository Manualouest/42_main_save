/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_rush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:49:02 by glaurich          #+#    #+#             */
/*   Updated: 2023/09/03 16:49:04 by glaurich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diff;

	diff = 0;
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && diff == 0)
	{
		diff = s1[i] - s2[i];
		i++;
	}
	if (diff == 0)
	{
		diff = s1[i] - s2[i];
	}
	return (diff);
}
