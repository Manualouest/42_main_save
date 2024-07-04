/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_routine_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:51:41 by mbirou            #+#    #+#             */
/*   Updated: 2024/07/02 15:58:09 by mbirou           ###   ########.fr       */
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

int	ps_check_death(t_philos *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (((time.tv_sec * 1000) + (time.tv_usec / 1000))
		- ((philo->last_eat.tv_sec * 1000) + (philo->last_eat.tv_usec / 1000))
		> philo->die)
	{
		pthread_mutex_lock(&philo->shared_mutex->writing_lock);
		pthread_mutex_unlock(&philo->shared_mutex->writing_lock);
		ps_status_update(philo, 0);
		return (0);
	}
	return (1);
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

int	ps_lock_unlock_forks(t_philos *philo, int is_lock)
{
	if (is_lock)
	{
		if (((philo->id % 2 == 0 || philo->next == NULL)
				&& (pthread_mutex_lock(&philo->left_fork->fork) != 0
					|| pthread_mutex_lock(&philo->my_fork->fork) != 0))
			|| (philo->id % 2 == 1 && philo->next != NULL
				&& (pthread_mutex_lock(&philo->my_fork->fork) != 0
					|| pthread_mutex_lock(&philo->left_fork->fork) != 0)))
		{
			write(1, "dead\n", 5);
			philo->status = 0;
			return (0);
		}
		return (1);
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->left_fork->fork);
		pthread_mutex_unlock(&philo->my_fork->fork);
		return (1);
	}
	pthread_mutex_unlock(&philo->my_fork->fork);
	pthread_mutex_unlock(&philo->left_fork->fork);
	return (1);
}
