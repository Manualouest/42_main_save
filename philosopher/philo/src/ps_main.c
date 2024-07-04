/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:45:54 by mbirou            #+#    #+#             */
/*   Updated: 2024/07/02 17:03:59 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

int	main(int argc, char **argv)
{
	int			*inputs;
	t_mutex		*mutexs;
	t_philos	*philos;

	if (!ps_input_parsing(argc, argv))
		return (0);
	inputs = ps_setup_inputs(argc, argv);
	mutexs = ps_setup_mutexs();
	philos = NULL;
	if (inputs != NULL || mutexs != NULL)
		philos = ps_setup_philos(inputs, mutexs);
	if (!inputs || !mutexs || !philos || !ps_are_mutexs_good(mutexs, philos))
	{
		if (!inputs || !mutexs || !philos)
			write(1, "Error\nShutdown, a malloc has failed.\n", 37);
		else
			write(1, "Error\nShutdown, a mutex has failed.\n", 36);
		ps_free(inputs, mutexs, philos);
		return (0);
	}
	ps_init_philos(philos, inputs[0]);
	ps_free(inputs, mutexs, philos);
	return (0);
}
