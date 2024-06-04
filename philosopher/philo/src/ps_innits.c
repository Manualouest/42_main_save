/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_innits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:32:37 by mbirou            #+#    #+#             */
/*   Updated: 2024/05/23 12:51:10 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

void	ps_innit_philos_stats(t_philos *philos, int id_int, int *stop,
	int *args)
{
	philos->stats = malloc(sizeof(*(philos->stats)));
	if (philos->stats)
	{
		philos->stats->id = id_int + 1;
		philos->stats->status = THINKING;
		philos->stats->sc_safety
			= pthread_mutex_init(&philos->stats->status_check, NULL);
		philos->stats->nb_meals_left = args[4];
		philos->stats->eat_time = args[2];
		philos->stats->sleep_time = args[3];
		philos->stats->death_time = args[1];
		philos->stats->keep_on = stop;
	}
	philos->fork = malloc(sizeof(*(philos->fork)));
	if (philos->fork)
	{
		philos->fork->is_free = 1;
		philos->fork->id = id_int + 1;
		philos->fork->mt_safety
			= pthread_mutex_init(&philos->fork->my_fork, NULL);
	}
	philos->time = NULL;
	philos->timestamp = NULL;
	philos->waitstamp = NULL;
}

void	ps_innit_philos(t_philos *philos, int *args, int *stop)
{
	t_philos	*first_philo;
	int			i;

	first_philo = philos;
	i = -1;
	while (++i < args[0])
	{
		philos->safety = -1;
		ps_innit_philos_stats(philos, i, stop, args);
		if (i + 1 < args[0])
			philos->next = malloc(sizeof(*(philos->next)));
		else
			philos->next = NULL;
		if (i + 1 < args[0])
			philos = philos->next;
		if (!philos)
			return ;
	}
	if (args[0] > 1 && first_philo)
		first_philo->left_fork = philos->fork;
	else
		philos->left_fork = NULL;
	if (philos)
		philos->next = NULL;
}

void	ps_insert_mutex(t_philos *philos, t_mutex *mutex_list)
{
	t_philos	*cpy_philos;

	cpy_philos = philos;
	while (cpy_philos != NULL)
	{
		if (cpy_philos->next != NULL)
			cpy_philos->next->left_fork = cpy_philos->fork;
		cpy_philos->mutex = mutex_list;
		cpy_philos = cpy_philos->next;
	}
}

void	ps_add_time_structs(t_philos *origine, t_philos *philo,
			t_time_stuff *start_time, int i)
{
	philo->timestamp = malloc(sizeof(*(philo->timestamp)));
	philo->waitstamp = malloc(sizeof(*(philo->waitstamp)));
	philo->time = malloc(sizeof(*(philo->time)));
	if (!philo->timestamp || !philo->waitstamp || !philo->time)
	{
		origine->safety = i - 1;
		return ;
	}
	philo->time->timeval = start_time->timeval;
	philo->stats->start_time = (start_time->timeval.tv_sec * 1000)
		+ (start_time->timeval.tv_usec / 1000);
}
