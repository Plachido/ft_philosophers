/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:47:28 by plpelleg          #+#    #+#             */
/*   Updated: 2021/12/02 23:56:49 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philo(pthread_mutex_t *forks, t_param *parameters,
	t_philo *philosopher)
{
	int				id;
	pthread_mutex_t	*tmp;

	id = -1;
	while (++id < parameters ->n_philo)
	{
		philosopher[id].id = id;
		philosopher[id].num_times_eaten = 0;
		philosopher[id].parameters = parameters;
		philosopher[id].left_fork = &forks[id];
		if (!id)
			philosopher[id].right_fork = &forks[parameters->n_philo - 1];
		else
			philosopher[id].right_fork = &forks[id - 1];
		if (!id)
		{
			tmp = philosopher[id].left_fork;
			philosopher[id].left_fork = philosopher[id].right_fork;
			philosopher[id].right_fork = tmp;
		}
	}
}

void	ft_initialize_mutex(t_param *parameters, pthread_mutex_t *mutex_array)
{
	int	i;

	i = -1;
	while (++i < parameters ->n_philo)
		pthread_mutex_init(&mutex_array[i], NULL);
}

void	ft_generate_threads(t_param *parameters, pthread_t *threads,
			t_philo *philosophers)
{
	int	i;

	i = -1;
	while (++i < parameters ->n_philo)
		pthread_create(&threads[i], NULL, &ft_routine, &philosophers[i]);
}

//parsing
static void	ft_set_param(int argc, char **argv, t_param *parameters)
{
	if (argc > 4 && argc < 7)
	{
		parameters -> n_philo = ft_atoi(argv[1], parameters);
		parameters -> time_to_die = ft_atoi(argv[2], parameters);
		parameters -> time_to_eat = ft_atoi(argv[3], parameters);
		parameters -> time_to_sleep = ft_atoi(argv[4], parameters);
		if (argc == 6)
			parameters -> n_times_to_eat = ft_atoi(argv[5], parameters);
		else
			parameters -> n_times_to_eat = -1;
	}
	else
		parameters -> error = 2;
}

t_param	*ft_parse(int argc, char **argv)
{
	t_param	*parameters;

	parameters = malloc(sizeof(t_param));
	if (!parameters)
	{
		write(1, "MALLOC ERROR\n", 14);
		ft_exit(parameters, NULL, NULL, NULL);
		return (NULL);
	}
	parameters -> error = 0;
	ft_set_param(argc, argv, parameters);
	if (parameters -> error)
	{
		write(1, "MALLOC ERROR\n", 14);
		ft_exit(parameters, NULL, NULL, NULL);
		return (NULL);
	}
	return (parameters);
}
