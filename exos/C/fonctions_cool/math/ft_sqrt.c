/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:16:00 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/24 18:16:02 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	temp;

	temp = 0;
	while (temp < 46341 && nb > (temp * temp))
		temp ++;
	if (nb == (temp * temp))
		return (temp);
	else
		return (0);
}
