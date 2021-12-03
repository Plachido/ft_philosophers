/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:32:33 by plpelleg          #+#    #+#             */
/*   Updated: 2021/12/03 19:53:10 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_param
{
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_times_to_eat;
	int				error;
	pthread_mutex_t	print;
}		t_param;

typedef struct s_philo
{
	int				id;
	int				num_times_eaten;
	t_param			*parameters;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct timeval	last_time_eaten;
}		t_philo;

//init.c
t_param				*ft_parse(int argc, char **argv);
void				ft_initialize_mutex(t_param *parameters,
						pthread_mutex_t *mutex_array);
void				ft_init_philo(pthread_mutex_t *forks, t_param *parameters,
						t_philo *philosopher);
void				ft_generate_threads(t_param *parameters, pthread_t *threads,
						t_philo *philosophers);

//utils.c
int					ft_atoi(char *str, t_param *parameters);
long unsigned int	ft_get_time(struct timeval tv);
void				ft_print(t_philo *philosopher, int code);

//exit.c
int					ft_all_have_eaten(t_philo *philo);
void				*ft_end_check(void *philosopher);
void				ft_set_error(t_param *parameters);
void				*ft_routine(void *args);
int					ft_exit(t_param *parameters, pthread_mutex_t *forks,
						pthread_t *threads, t_philo *philosophers);
#endif