/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:49:28 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/26 18:39:57 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bit_info	bit_info;

void	ft_handler(int sig, siginfo_t *info, void *oldact)
{
	(void)oldact;
	bit_info.caracter = bit_info.caracter << 1;
	if (sig == SIGUSR2)
		bit_info.caracter++;
	bit_info.bits++;
	if (bit_info.is_start++, bit_info.is_start == 1)
	{
		write(1, "\nMessage received from ", 23);
		ft_putnbr(info->si_pid);
		write(1, ": ", 2);
		bit_info.is_start = 1;
	}
	if (bit_info.bits == 8)
	{
		write(1, &(char){bit_info.caracter}, 1);
		if (bit_info.caracter == 0)
			bit_info.is_start = 0;
	 	bit_info.bits = 0;
		bit_info.caracter = 0;
	}
	kill(info->si_pid, SIGUSR1);
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
