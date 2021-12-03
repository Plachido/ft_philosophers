/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:32:45 by plpelleg          #+#    #+#             */
/*   Updated: 2021/12/03 19:53:43 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eat(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->left_fork);
	ft_print(philosopher, 1);
	pthread_mutex_lock(philosopher->right_fork);
	ft_print(philosopher, 1);
	ft_print(philosopher, 2);
	usleep(philosopher->parameters->time_to_eat * 1000);
	pthread_mutex_unlock(philosopher->left_fork);
	pthread_mutex_unlock(philosopher->right_fork);
	philosopher-> num_times_eaten += 1;
}

void	*ft_routine(void *philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	gettimeofday(&philosopher->last_time_eaten, NULL);
	ft_eat(philosopher);
	gettimeofday(&philosopher->last_time_eaten, NULL);
	ft_print(philosopher, 3);
	usleep(philosopher->parameters->time_to_sleep * 1000);
	while (1)
	{
		ft_print(philosopher, 4);
		ft_eat(philosopher);
		gettimeofday(&philosopher->last_time_eaten, NULL);
		ft_print(philosopher, 3);
		usleep(philosopher->parameters->time_to_sleep * 1000);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	t_param			*parameters;
	t_philo			*philosophers;

	parameters = ft_parse(argc, argv);
	if (!parameters)
		return (0);
	pthread_mutex_init(&parameters->print, NULL);
	forks = malloc(sizeof(pthread_mutex_t) * parameters->n_philo);
	threads = malloc(sizeof(pthread_t) * (parameters ->n_philo + 2));
	philosophers = malloc(sizeof(t_philo) * parameters->n_philo);
	if (!forks || !threads || !philosophers)
		return (ft_exit(parameters, NULL, NULL, NULL));
	ft_initialize_mutex(parameters, forks);
	ft_init_philo(forks, parameters, philosophers);
	ft_generate_threads(parameters, threads, philosophers);
	pthread_create(&threads[parameters ->n_philo], NULL,
		&ft_end_check, philosophers);
	pthread_join(threads[parameters->n_philo], NULL);
	ft_exit(parameters, forks, threads, philosophers);
	return (0);
}
