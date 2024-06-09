/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:43:28 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/09 20:27:44 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_mutex
{
	pthread_mutex_t	writing_lock;
	int				wl_safety;
	pthread_mutex_t	checking_lock;
	int				cl_safety;
}					t_mutex;

typedef struct	s_philos
{
	pthread_t		philo;
	int				id;
	int				die;
	int				eat;
	int				sleep;
	int				nb_meals;
	int				status;
	int				*my_fork;
	int				*left_fork;
	pthread_mutex_t	status_check;
	int				sc_safety;
	long int		start;
	struct timeval	last_eat;
	struct s_mutex	*shared_mutex;
	struct s_philos	*next;
}					t_philos;

// ps_inits.c
int			*ps_setup_inputs(int argc, char **argv);
t_mutex		*ps_setup_mutexs(void);
t_philos	*ps_setup_philos(int *inputs, t_mutex *mutexs);

// overseer.c
void		ps_init_philos(t_philos *philos, int nb_philos);
void		ps_overseer_start(t_philos *philos, int nb_philos);

// ps_routine_main.c
void		*ps_routine_main(void *void_philo);
void		ps_putmsg(t_philos *philo, int msg, int skip);

// ps_routine_utils.c
int			ps_status_update(t_philos *philo, int n_status);
void		ps_usleep(t_philos *philo, int time, int max);
void		ps_check_death(t_philos *philo);
int			ps_meal_update(t_philos *philo, int inter);

// ps_utils.c
long int	ps_atoi(const char *num);
void		ps_putnbr(long int n);

// ps_parsing.c
int			ps_input_parsing(int nb_params, char **params);
int			ps_are_mutexs_good(t_mutex *mutexs, t_philos *philos);

// ps_free.c
void		ps_free(int *inputs, t_mutex *mutexs, t_philos *philos);

#endif