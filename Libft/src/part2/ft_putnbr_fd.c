/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:01:14 by mbirou            #+#    #+#             */
/*   Updated: 2024/10/10 23:54:28 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	temp;
	char			num;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		temp = n * -1;
	}
	else
		temp = n;
	if (temp > 9)
		ft_putnbr_fd(temp / 10, fd);
	num = temp % 10 + '0';
	write(fd, &num, 1);
}
