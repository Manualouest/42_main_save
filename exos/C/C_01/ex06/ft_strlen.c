/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:17:16 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/17 13:18:48 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	tt;

	tt = 0;
	while (str[tt] != 0)
	{
		tt = tt + 1;
	}
	return (tt);
}
