/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_routine_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:36:34 by mbirou            #+#    #+#             */
/*   Updated: 2024/07/02 16:58:41 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

void	ps_find_msg(t_philos *philo, int msg, int skip)
{
	if (msg == 0)
	{
		write(1, " has taken a fork\n", 18);
		if (!skip)
			ps_putmsg(philo, 0, 1);
	}
	else if (msg == 1)
		write(1, " is eating\n", 11);
	else if (msg == 2)
		write(1, " is sleeping\n", 13);
	else if (msg == 3)
		write(1, " is thinking\n", 13);
}

void	ps_putmsg(t_philos *philo, int msg, int skip)
{
	struct timeval	time;

	if (!skip && pthread_mutex_lock(&philo->shared_mutex->writing_lock) != 0)
	{
		philo->status = 0;
		return ;
	}
	gettimeofday(&time, NULL);
	if (!ps_status_update(philo, -1))
	{
		pthread_mutex_unlock(&philo->shared_mutex->writing_lock);
		return ;
	}
	ps_putnbr((time.tv_sec * 1000) + (time.tv_usec / 1000) - philo->start);
	write(1, " ", 1);
	ps_putnbr(philo->id);
	ps_find_msg(philo, msg, skip);
	if (!skip)
		pthread_mutex_unlock(&philo->shared_mutex->writing_lock);
}

void	ps_go_eat(t_philos *philo)
{
	while (ps_status_update(philo, -1))
	{
		if (philo->left_fork)
		{
			if (!ps_lock_unlock_forks(philo, 1))
				return ;
			if (philo->my_fork && philo->left_fork && philo->my_fork->is_free
				&& philo->left_fork->is_free)
			{
				philo->my_fork->is_free = 0;
				philo->left_fork->is_free = 0;
				ps_lock_unlock_forks(philo, 0);
				ps_putmsg(philo, 0, 0);
				gettimeofday(&philo->last_eat, NULL);
				ps_putmsg(philo, 1, 0);
				ps_meal_update(philo, 1);
				return ;
			}
			ps_lock_unlock_forks(philo, 0);
		}
		usleep(128);
		ps_check_death(philo);
	}
}

void	ps_release_forks(t_philos *philo)
{
	if (!ps_lock_unlock_forks(philo, 1))
		return ;
	philo->my_fork->is_free = 1;
	philo->left_fork->is_free = 1;
	ps_lock_unlock_forks(philo, 0);
}

void	*ps_routine_main(void *void_philo)
{
	t_philos	*philo;

	philo = (t_philos *)void_philo;
	gettimeofday(&philo->last_eat, NULL);
	ps_putmsg(philo, 3, 0);
	while (ps_status_update(philo, -1))
	{
		ps_go_eat(philo);
		if (ps_status_update(philo, -1) && philo->left_fork)
		{
			ps_usleep(philo, philo->eat, philo->die);
			if (ps_status_update(philo, -1))
				ps_release_forks(philo);
		}
		if (ps_status_update(philo, -1) && philo->left_fork)
		{
			ps_putmsg(philo, 2, 0);
			ps_usleep(philo, philo->sleep, philo->die - philo->eat);
		}
		if (ps_status_update(philo, -1) && philo->left_fork)
			ps_putmsg(philo, 3, 0);
		if (philo->die - philo->sleep - philo->eat > 0 && philo->left_fork)
			usleep((philo->die - philo->sleep - philo->eat) * 100);
	}
	return (0);
}
