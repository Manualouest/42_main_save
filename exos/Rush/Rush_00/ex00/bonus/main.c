/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:55:06 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/19 13:27:11 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	rush(int x, int y);

int	main(void)
{
	rush(5, 5);
	rush(1, 5);
	rush(5, 1);
	rush(0, 5);
	rush(5, 0);
	rush(0, 0);
	return (0);
}