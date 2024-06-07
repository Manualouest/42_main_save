/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_philosopher_brain.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 23:29:32 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/07 22:24:20 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

int	ps_try_fork(t_philos *philo, t_fork *fork1, t_fork *fork2)
{
	if (pthread_mutex_lock(&philo->mutex->checking) != 0)
		return (0);
	if (fork1->is_free == 1 && fork2->is_free == 1)
	{
		fork1->is_free = 0;
		fork2->is_free = 0;
		ps_write_msg(philo->timestamp, philo, 1, 0);
		ps_write_msg(philo->timestamp, philo, 1, 0);
		pthread_mutex_unlock(&philo->mutex->checking);
		return (1);
	}
	pthread_mutex_unlock(&philo->mutex->checking);
	return (0);
}

void	ps_take_forks(t_philos *philo)
{
	int	got_forks;

	got_forks = 0;
	while (ps_is_alive(philo) && !got_forks)
	{
		if (philo->fork && philo->left_fork)
			got_forks = ps_try_fork(philo, philo->fork, philo->left_fork);
		// else if (philo->fork && philo->left_fork)
		// 	got_forks = ps_try_fork(philo, philo->fork, philo->left_fork);
		// if (ps_is_alive(philo))
		// 	ps_check_for_death(philo);
	}
	if (ps_is_alive(philo) && got_forks)
		ps_philo_status(philo, EATING);
}

int	ps_philo_status(t_philos *philo, int new)
{
	int	ret;

	ret = 0;
	if (pthread_mutex_lock(&philo->status) != 0)
	{
		philo->stats->status = DEAD;
		return (DEAD);
	}
	if (new < 0)
		ret = philo->stats->status;
	else if (new >= EATING && new <= DEAD)
		philo->stats->status = new;
	pthread_mutex_unlock(&philo->status);
	return (ret);
}

void	ps_make_philo_think(t_philos *philo)
{
	// gettimeofday(&philo->waitstamp->timeval, NULL);
	// gettimeofday(&philo->timestamp->timeval, NULL);
	usleep(((philo->stats->death_time * 1000)
			- (philo->stats->sleep_time * 1000)
			- (philo->stats->eat_time * 1000)) / 10);
	// while (ps_is_alive(philo)
	// 	&& ((((philo->timestamp->timeval.tv_sec - 1
	// 					- philo->waitstamp->timeval.tv_sec) * 1000000)
	// 			+ (1000000 - philo->waitstamp->timeval.tv_usec)
	// 			+ philo->timestamp->timeval.tv_usec))
	// 	< ((philo->stats->death_time * 1000)
	// 		- (philo->stats->sleep_time * 1000)
	// 		- (philo->stats->eat_time * 1000)) / 10)
	// {
	// 	usleep(128);
	// 	gettimeofday(&philo->timestamp->timeval, NULL);
	// }
}

void	*ps_philosopher_brain(void *vd_philo)
{
	t_philos	*philo;

	philo = (t_philos *)vd_philo;
	ps_write_msg(philo->timestamp, philo, 4, 0);
	while (ps_is_alive(philo))
	{
		if (ps_is_alive(philo) && ps_philo_status(philo, -1) == THINKING)
		{
			ps_take_forks(philo);
			ps_meal_check(philo, 1);
			ps_write_msg(philo->timestamp, philo, 2, 0);
			gettimeofday(&philo->time->timeval, NULL);
			ps_wait_time(philo, philo->stats->eat_time, EATING);
		}
		if (ps_is_alive(philo) && ps_philo_status(philo, -1) == EATING)
			ps_make_philo_sleep(philo);
		if (ps_is_alive(philo) && ps_philo_status(philo, -1) == SLEEPING)
		{
			ps_philo_status(philo, THINKING);
			ps_write_msg(philo->timestamp, philo, 4, 0);
			ps_make_philo_think(philo);
		}
	}
	return (0);
}
