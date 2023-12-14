/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:34:23 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/29 10:34:29 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	num;
	int	sign;
	int	temp;

	num = 0;
	sign = 1;
	temp = 0;
	while (str[temp] != 0 && (str[temp] == ' '
			|| (str[temp] >= 9 && str[temp] <= 13)))
		temp ++;
	while (str[temp] != 0
		&& (str[temp] == '+' || str[temp] == '-'))
	{
		if (str[temp] == '-')
			sign = sign * -1;
		temp ++;
	}
	while (str[temp] != 0 && (str[temp] >= '0' && str[temp] <= '9'))
		num = num * 10 + (str[temp++] - '0');
	return (num * sign);
}
