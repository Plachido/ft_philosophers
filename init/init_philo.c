/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:47:28 by plpelleg          #+#    #+#             */
/*   Updated: 2021/11/28 22:15:58 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static t_philo   *ft_init_philo(int id, pthread_mutex_t **forks, t_param *parameters)
{
    t_philo *philosopher;

    philosopher = malloc(sizeof(t_philo));
    philosopher->id = id;
    philosopher->parameters = parameters;
    philosopher -> left_fork = forks[id];
    if (!id)
        philosopher->right_fork = forks[parameters->n_philo - 1];
    else
        philosopher->right_fork = forks[id-1];
    return(philosopher);
}

void    ft_generate_threads(t_param *parameters, pthread_mutex_t **forks, pthread_t *threads, t_philo **philosophers)
{
    int i;

    i = -1;
    while (++i < parameters ->n_philo)
    {
        philosophers[i] = ft_init_philo(i, forks, parameters);
        pthread_create(&threads[i], NULL, &routine, philosophers[i]);
    }
}

void ft_close_threads(t_param *parameters, pthread_t *threads)
{
    int i;

    i = -1;
    while (++i < parameters->n_philo)
        pthread_join(threads[i], NULL);
}