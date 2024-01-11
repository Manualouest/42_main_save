/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:35:18 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/17 11:09:45 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_num(int c, int d, int u)
{
	int	a;
	int	b;
	int	e;

	a = c + '0';
	b = d + '0';
	e = u + '0';
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &e, 1);
	if (c * 100 + d * 10 + u != 789)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	c;
	int	d;
	int	u;

	c = 0;
	while (c <= 7)
	{
		d = c + 1;
		while (d <= 8)
		{
			u = d + 1;
			while (u <= 9)
			{
				write_num(c, d, u);
				u = u + 1;
			}
			d = d + 1;
		}
		c = c + 1;
	}
}
