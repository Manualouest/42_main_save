/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derey <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 08:42:55 by derey             #+#    #+#             */
/*   Updated: 2023/08/19 19:09:54 by derey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

extern	void	ft_putchar(int i);

void	rushchar(int x, int y, int a, int c)
{
	if ((a == 1 && c == 1) || (a == x && c == 1)
		|| (a == 1 && c == y) || (a == x && c == y))
	{
		ft_putchar(4);
	}
	if (a > 1 && a < x && (c == 1 || c == y))
	{
		ft_putchar(5);
	}
	if (c > 1 && c < y)
	{
		if (a == 1 || a == x)
		{
			ft_putchar(6);
		}
		else
			ft_putchar(2);
	}	
}

void	rush(int x, int y)
{
	int	a;
	int	c;

	a = 1;
	c = 1;
	if (x <= 0 || y <= 0)
		write(1, "entrer des nombers entier positif svp", 37);
	else
	{
		while (c <= y)
		{
			a = 1;
			while (a <= x)
			{
				rushchar(x, y, a, c);
				if (a == x && c <= y)
				{
					ft_putchar(10);
				}
				a++;
			}
			c++;
		}
	}
}
