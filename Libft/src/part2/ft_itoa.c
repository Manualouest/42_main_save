/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:12:12 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/03 19:12:12 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa(int n)
{
	int		i;
	int		tp_num;
	char	*nbr;

	i = (n <= 0);
	tp_num = n;
	while (tp_num != 0 && ++i > 0)
		tp_num /= 10;
	nbr = malloc(sizeof(*nbr) * (i + 1));
	if (!nbr)
		return (NULL);
	nbr[i] = 0;
	tp_num = n;
	while (--i >= (tp_num < 0))
	{
		nbr[i] = (tp_num % 10) * (1 - 2 * (n < 0)) + '0';
		tp_num /= 10;
	}
	if (n < 0)
		nbr[0] = '-';
	return (nbr);
}
