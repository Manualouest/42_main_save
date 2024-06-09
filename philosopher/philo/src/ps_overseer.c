/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_overseer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:53:10 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/09 22:23:15 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

void	ps_stop_threads(t_philos *philos)
{
	t_philos	*cpy_philos;

	cpy_philos = philos;
	while (cpy_philos)
	{
		ps_status_update(cpy_philos, 0);
		cpy_philos = cpy_philos->next;
	}
}

void	ps_join_threads(t_philos *philos, int safety_num)
{
	t_philos	*cpy_philos;

	cpy_philos = philos;
	if (safety_num != -1)
	{
		if (pthread_mutex_lock(&philos->shared_mutex->writing_lock) != 0)
			return ;
		write(1, "Shutdown, error while creating threads.\n", 40);
		pthread_mutex_unlock(&philos->shared_mutex->writing_lock);
		while (--safety_num >= 0 && cpy_philos)
		{
			pthread_join(cpy_philos->philo, NULL);
			cpy_philos = cpy_philos->next;
		}
		return ;
	}
	while (cpy_philos)
	{
		pthread_join(cpy_philos->philo, NULL);
		cpy_philos = cpy_philos->next;
	}
}

void	ps_init_philos(t_philos *philos, int nb_philos)
{
	int				create_safety;
	t_philos		*cpy_philos;
	struct timeval	time;
	long int		time_int;

	create_safety = 0;
	cpy_philos = philos;
	gettimeofday(&time, NULL);
	time_int = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	while (cpy_philos && ++create_safety > 0)
	{
		cpy_philos->start = time_int;
		if (pthread_create(&cpy_philos->philo, NULL,
				ps_routine_main, (void *)cpy_philos) != 0)
			break ;
		cpy_philos = cpy_philos->next;
	}
	if (cpy_philos)
	{
		ps_stop_threads(philos);
		ps_join_threads(philos, create_safety);
	}
	else
		ps_overseer_start(philos, nb_philos);
}

void	ps_write_death_message(t_philos *philos)
{
	struct timeval	time;

	if (pthread_mutex_lock(&philos->shared_mutex->writing_lock) != 0)
		return ;
	gettimeofday(&time, NULL);
	ps_putnbr((time.tv_sec * 1000) + (time.tv_usec / 1000) - philos->start);
	write(1, " ", 1);
	ps_putnbr(philos->id);
	write(1, " died\n", 6);
	pthread_mutex_unlock(&philos->shared_mutex->writing_lock);
}

void	ps_overseer_start(t_philos *philos, int nb_philos)
{
	t_philos	*cpy_philos;
	int			nb_finished;

	cpy_philos = philos;
	nb_finished = 0;
	while (ps_status_update(cpy_philos, -1) && nb_finished != nb_philos)
	{
		if (ps_meal_update(cpy_philos, 0) == 0)
			nb_finished ++;
		else
			nb_finished = 0;
		if (cpy_philos->next)
			cpy_philos = cpy_philos->next;
		else
		{
			usleep(128);
			cpy_philos = philos;
		}
	}
	ps_stop_threads(philos);
	if (nb_finished != nb_philos)
		ps_write_death_message(cpy_philos);
	ps_join_threads(philos, -1);
}
