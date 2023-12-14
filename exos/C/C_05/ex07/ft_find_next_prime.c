/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:28:20 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/24 18:28:22 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	temp;

	temp = 2;
	if (nb < 2)
		return (0);
	while (temp <= nb / temp)
	{
		if ((nb % temp) == 0)
			return (0);
		temp ++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	temp;

	temp = nb;
	while (ft_is_prime(temp) != 1)
	{
		temp ++;
	}
	return (temp);
}
