/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:55:09 by plpelleg          #+#    #+#             */
/*   Updated: 2021/12/03 19:48:31 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_all_have_eaten(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->parameters->n_philo)
		if (philo[i].num_times_eaten < philo[i].parameters->n_times_to_eat)
			break ;
	if (i == philo->parameters->n_philo)
		return (1);
	return (0);
}

void	*ft_end_check(void *philosopher)
{
	int				i;
	t_philo			*philo;
	struct timeval	now;

	i = -1;
	philo = (t_philo *)philosopher;
	while (++i || 1)
	{
		gettimeofday(&now, NULL);
		if ((ft_get_time(now) - (ft_get_time(philo[i].last_time_eaten))
			) > (long unsigned int)philo[i].parameters-> time_to_die)
		{
			ft_print(&philo[i], 5);
			break ;
		}
		else if (philo->parameters->n_times_to_eat > -1
			&& ft_all_have_eaten(philo))
		{
			ft_print(&philo[i], 6);
			break ;
		}
		if (i == philo[i].parameters->n_philo - 1)
			i = -1;
	}
	return (NULL);
}

void	ft_set_error(t_param *parameters)
{
	write(1, "PARAMETER ERROR\n", 17);
	parameters -> error = 1;
}

int	ft_exit(t_param *parameters, pthread_mutex_t *forks,
	pthread_t *threads, t_philo *philosophers)
{
	int	i;

	i = -1;
	if (threads)
	{
		while (++i < parameters->n_philo)
			pthread_detach(threads[i]);
		free(threads);
	}
	i = -1;
	if (parameters)
	{
		pthread_mutex_destroy(&parameters->print);
		free(parameters);
	}
	if (forks)
	{
		while (++i < parameters->n_philo)
			pthread_mutex_destroy(&forks[i]);
		free(forks);
	}
	if (philosophers)
		free(philosophers);
	return (0);
}
