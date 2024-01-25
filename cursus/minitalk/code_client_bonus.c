/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_client_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:55:49 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/24 18:23:26 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_receipt(int sig)
{
	(void)sig;
	write(1, "Server confirmed receiving a message.\n", 38);
}

void	ft_send_sig(int pid, char c)
{
	int		bit;
	char	tp_c;

	bit = 0;
	while (++bit < 9)
	{
		tp_c = c >> (8 - bit);
		if ((tp_c & 1) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3 || ft_has_letter(argv[1]))
		return (ft_send_error(argc, 1));
	signal(SIGUSR1, ft_receipt);
	pid = ft_atoi(argv[1]);
	i = -1;
	while (argv[2][++i] != 0)
		ft_send_sig(pid, argv[2][i]);
	ft_send_sig(pid, (char)0);
	return (0);
}
