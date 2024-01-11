/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 09:56:35 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/19 13:24:15 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_putchar(int current_char);

void	rush_tests(int current_x, int current_y, int memox, int memoy)
{
	if (current_y == memoy && current_x == memox)
		ft_putchar(0);
	else if (current_y == memoy && current_x == 1)
		ft_putchar(0);
	else if (current_y == 1 && current_x == memox)
		ft_putchar(3);
	else if (current_y == 1 && current_x == 1)
		ft_putchar(3);
	else if ((current_y == memoy || current_y == 1)
		&& (current_x < memox && current_x > 1))
		ft_putchar(1);
	else if (current_y < memoy && current_y > 1)
	{
		if (current_x == memox || current_x == 1)
			ft_putchar(1);
		if (current_x < memox && current_x > 1)
			ft_putchar(2);
	}
	if (current_x == 1)
		ft_putchar(6);
}

void	rush(int x, int y)
{
	int	memox;
	int	memoy;

	memox = x;
	memoy = y;
	while (y > 0)
	{
		x = memox;
		while (x > 0)
		{
			rush_tests(x, y, memox, memoy);
			x--;
		}
		y--;
	}
}
