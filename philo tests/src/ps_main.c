/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:38:46 by mbirou            #+#    #+#             */
/*   Updated: 2024/05/20 19:39:18 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

int	*ps_simplify_args(int nb_args, char **params)
{
	int	*param_list;

	param_list = malloc(sizeof(int) * 5);
	if (!param_list)
		return (NULL);
	param_list[0] = ps_atoi(params[1]);
	param_list[1] = ps_atoi(params[2]);
	param_list[2] = ps_atoi(params[3]);
	param_list[3] = ps_atoi(params[4]);
	if (nb_args == 6)
		param_list[4] = ps_atoi(params[5]);
	else
		param_list[4] = -1;
	return (param_list);
}

void	ps_innit_mutex_list(t_mutex *mutex_list)
{
	if (mutex_list)
	{
		mutex_list->cp_safety = pthread_mutex_init(&mutex_list
				->checking_privilege, NULL);
		mutex_list->wp_safety = pthread_mutex_init(&mutex_list
				->writing_privilege, NULL);
	}
}

int	main(int argc, char **argv)
{
	int					*args;
	int					stop;
	t_mutex				*mutex_list;
	t_philos			*philos;
	struct s_time_stuff	*time;

	if (!ps_input_parsing(argc, argv))
		return (0);
	args = ps_simplify_args(argc, argv);
	stop = 1;
	mutex_list = malloc(sizeof(*mutex_list));
	ps_innit_mutex_list(mutex_list);
	philos = malloc(sizeof(*philos));
	ps_innit_philos(philos, args, &stop);
	time = malloc(sizeof(*time));
	if (!mutex_list || !philos || !time || !args)
	{
		write(2, "Malloc failed.\n", 15);
		ps_free_everything(philos, args, time, mutex_list);
		return (0);
	}
	ps_insert_mutex(philos, mutex_list);
	gettimeofday(&time->timeval, &time->timezone);
	ps_start_threads(philos, time, &stop, args[0]);
	ps_free_everything(philos, args, time, mutex_list);
}
