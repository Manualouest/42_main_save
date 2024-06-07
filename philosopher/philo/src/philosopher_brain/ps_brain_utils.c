/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_brain_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 23:48:37 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/07 22:25:09 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

void	ps_find_msg(int msg_id)
{
	if (msg_id == 0)
		write(1, " died\n", 6);
	if (msg_id == 1)
		write(1, " has taken a fork\n", 18);
	if (msg_id == 2)
		write(1, " is eating\n", 11);
	if (msg_id == 3)
		write(1, " is sleeping\n", 13);
	if (msg_id == 4)
		write(1, " is thinking\n", 13);
}

void	ps_write_msg(t_time_stuff *timestamp, t_philos *philo, int msg_id,
			int backdoor)
{
	char	*text;

	if (pthread_mutex_lock(&philo->mutex->writing) != 0)
		return ;
	gettimeofday(&timestamp->timeval, NULL);
	if (!ps_is_alive(philo) && !backdoor)
	{
		pthread_mutex_unlock(&philo->mutex->writing);
		return ;
	}
	text = ps_itoa(((timestamp->timeval.tv_sec * 1000)
				+ (timestamp->timeval.tv_usec / 1000))
			- philo->stats->start_time);
	write(1, text, ps_strlen(text));
	usleep(128);
	free(text);
	write(1, " ", 1);
	text = ps_itoa(philo->stats->id);
	usleep(128);
	write(1, text, ps_strlen(text));
	usleep(128);
	ps_find_msg(msg_id);
	usleep(128);
	free(text);
	pthread_mutex_unlock(&philo->mutex->writing);
}

void	ps_wait_time(t_philos *philo, int wait, int reason)
{
	// gettimeofday(&philo->waitstamp->timeval, NULL);
	gettimeofday(&philo->timestamp->timeval, NULL);
	
	(void)wait;
	if (reason == EATING
		&& (((((philo->timestamp->timeval.tv_sec - 1
					- philo->time->timeval.tv_sec)
				* 1000000) + (1000000 - philo->time->timeval.tv_usec)
			+ philo->timestamp->timeval.tv_usec) / 1000))
				+ philo->stats->eat_time < philo->stats->death_time)
		usleep(philo->stats->eat_time * 1000);
	else if (reason == EATING)
	{
		usleep((((((philo->timestamp->timeval.tv_sec - 1
					- philo->time->timeval.tv_sec)
				* 1000000) + (1000000 - philo->time->timeval.tv_usec)
			+ philo->timestamp->timeval.tv_usec) / 1000))
				+ philo->stats->eat_time - philo->stats->death_time);
		ps_philo_status(philo, DEAD);
	}

	if (reason == SLEEPING
		&& (((((philo->timestamp->timeval.tv_sec - 1
					- philo->time->timeval.tv_sec)
				* 1000000) + (1000000 - philo->time->timeval.tv_usec)
			+ philo->timestamp->timeval.tv_usec) / 1000))
				+ philo->stats->eat_time +  philo->stats->sleep_time
				< philo->stats->death_time)
		usleep(philo->stats->sleep_time * 1000);
	else if (reason == SLEEPING)
	{
		// write(1, "hey", 3);
		// printf("\n3philo: %d, %d\n",philo->stats->id , philo->stats->status);
		// printf("time: %ld", (((((philo->timestamp->timeval.tv_sec - 1
		// 			- philo->time->timeval.tv_sec)
		// 		* 1000000) + (1000000 - philo->time->timeval.tv_usec)
		// 	+ philo->timestamp->timeval.tv_usec) / 1000))
		// 		+ philo->stats->eat_time +  philo->stats->sleep_time
		// 		- philo->stats->death_time);
		usleep((((((philo->timestamp->timeval.tv_sec - 1
					- philo->time->timeval.tv_sec)
				* 1000000) + (1000000 - philo->time->timeval.tv_usec)
			+ philo->timestamp->timeval.tv_usec) / 1000))
				+ philo->stats->eat_time +  philo->stats->sleep_time
				- philo->stats->death_time);
		ps_philo_status(philo, DEAD);
	}

		// if (((((philo->timestamp->timeval.tv_sec - 1 - philo->time->timeval.tv_sec)
		// 				* 1000000) + (1000000 - philo->time->timeval.tv_usec)
		// 			+ philo->timestamp->timeval.tv_usec) / 1000)
		// 	>= philo->stats->death_time)


	// 	while (ps_is_alive(philo)
	// 		&& ((((philo->timestamp->timeval.tv_sec - 1
	// 						- philo->waitstamp->timeval.tv_sec) * 1000000)
	// 				+ (1000000 - philo->waitstamp->timeval.tv_usec)
	// 				+ philo->timestamp->timeval.tv_usec) / 1000)
	// 		< wait)
	// 	{
	// 		// ps_check_for_death(philo);
	// 		usleep(128);
	// 		gettimeofday(&philo->timestamp->timeval, NULL);
	// 	}
	// }
}

void	ps_make_philo_sleep(t_philos *philo)
{
	ps_write_msg(philo->timestamp, philo, 3, 0);
	if (pthread_mutex_lock(&philo->mutex->checking) != 0)
	{
		philo->stats->status = DEAD;
		return ;
	}
	philo->fork->is_free = 1;
	philo->left_fork->is_free = 1;
	pthread_mutex_unlock(&philo->mutex->checking);
	ps_philo_status(philo, SLEEPING);
	ps_wait_time(philo, philo->stats->sleep_time, SLEEPING);
}

int	ps_meal_check(t_philos *philo, int ate)
{
	int	ret;

	ret = 0;
	if (pthread_mutex_lock(&philo->status) != 0)
	{
		philo->stats->status = DEAD;
		write(1, "test\n", 5);
		return (ret);
	}
	if (ate && philo->stats->nb_meals_left > 0)
		philo->stats->nb_meals_left --;
	ret = philo->stats->nb_meals_left;
	pthread_mutex_unlock(&philo->status);
	return (ret);
}