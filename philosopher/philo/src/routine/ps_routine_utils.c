/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_routine_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:51:41 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/09 22:24:18 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

int	ps_status_update(t_philos *philo, int n_status)
{
	int	ret;

	if (pthread_mutex_lock(&philo->status_check) != 0)
	{
		philo->status = 0;
		return (0);
	}
	if (n_status != -1)
		philo->status = n_status;
	ret = philo->status;
	pthread_mutex_unlock(&philo->status_check);
	return (ret);
}

void	ps_usleep(t_philos *philo, int time, int max)
{
	if (time < max)
		usleep(time * 1000);
	else
	{
		usleep(max * 1000);
		ps_status_update(philo, 0);
	}
}

void	ps_check_death(t_philos *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (((time.tv_sec * 1000) + (time.tv_usec / 1000))
		- ((philo->last_eat.tv_sec * 1000) + (philo->last_eat.tv_usec / 1000))
		> philo->die)
	{
		pthread_mutex_lock(&philo->shared_mutex->writing_lock);
		write(1, "\n", 1);
		ps_putnbr(((time.tv_sec * 1000) + (time.tv_usec / 1000))
		- ((philo->last_eat.tv_sec * 1000) + (philo->last_eat.tv_usec / 1000)));
		write(1, "\n", 1);
		ps_putnbr(((time.tv_sec * 1000) + (time.tv_usec / 1000)));
		write(1, "\n", 1);
		ps_putnbr(((philo->last_eat.tv_sec * 1000) + (philo->last_eat.tv_usec / 1000)));
		write(1, "\n", 1);
		ps_putnbr(philo->start);
		write(1, "\n", 1);
		pthread_mutex_unlock(&philo->shared_mutex->writing_lock);
		ps_status_update(philo, 0);
	}
}

int	ps_meal_update(t_philos *philo, int inter)
{
	int	ret;

	if (pthread_mutex_lock(&philo->status_check) != 0)
	{
		philo->status = 0;
		return (0);
	}
	if (philo->nb_meals > 0)
		philo->nb_meals -= inter;
	ret = philo->nb_meals;
	pthread_mutex_unlock(&philo->status_check);
	return (ret);
}
