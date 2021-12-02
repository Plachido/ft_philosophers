/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:55:09 by plpelleg          #+#    #+#             */
/*   Updated: 2021/12/02 23:48:07 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_set_error(int code, t_param *parameters)
{
	if (code == 1)
		write(1, "PARAMETER ERROR\n", 17);
	parameters -> error = code;
}

static void	ft_close_free(t_param *parameters, pthread_mutex_t *forks,
	pthread_t *threads, t_philo *philosophers)
{
	int	i;
	int	n_philo;

	n_philo = parameters->n_philo;
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
		while (++i < n_philo)
			pthread_mutex_destroy(&forks[i]);
		free(forks);
	}
	if (philosophers)
		free(philosophers);
}

int	ft_exit(t_param *parameters, pthread_mutex_t *forks,
	pthread_t *threads, t_philo *philosophers)
{
	ft_close_free(parameters, forks, threads, philosophers);
	return (0);
}
