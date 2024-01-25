/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:49:28 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/24 18:12:53 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig, siginfo_t *info, void *oldact)
{
	static int	bit_info[3];

	(void)oldact;
	if (!bit_info[2] || (bit_info[1] == 0 && bit_info[0] == 8))
		bit_info[2] = 0;
	if (!bit_info[0] || bit_info[0] == 8)
	{
		bit_info[0] = 0;
		bit_info[1] = 0;
	}
	bit_info[1] = bit_info[1] << 1;
	if (sig == SIGUSR2)
		bit_info[1]++;
	bit_info[0]++;
	if (bit_info[0] == 8)
		write(1, &(char){bit_info[1]}, 1);
	if (bit_info[2]++, bit_info[2] == 1)
	{
		write(1, "\nMessage received from ", 23);
		ft_putnbr(info->si_pid);
		write(1, ": ", 2);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 1)
		return (ft_send_error(argc, 0));
	(void)argv;
	write(1, "Server pid: ", 12);
	ft_putnbr(getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &ft_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1 == 1)
		pause();
	return (0);
}
