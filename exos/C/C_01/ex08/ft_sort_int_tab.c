/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:15:46 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/18 09:53:14 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	pos;

	pos = 0;
	while (pos < size - 1)
	{
		pos ++;
		if (tab[pos - 1] > tab[pos])
		{
			ft_swap(&tab[pos - 1], &tab[pos]);
			pos = 0;
		}
	}
}
