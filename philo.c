/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:32:45 by plpelleg          #+#    #+#             */
/*   Updated: 2021/11/28 22:25:27 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header/philo.h"

# include <stdio.h>
void    *routine(void *args)
{
    t_philo *philosopher;
    
    philosopher = (t_philo*)args;
    printf("%d\n", philosopher->id);
    return(0);
}

int main(int argc, char **argv)
{
    t_param *parameters;
    pthread_mutex_t **forks;
    pthread_t *threads;
    t_philo **philosophers;
    
    parameters = ft_parse(argc, argv);
    if (!parameters)
        return(0);
    forks = malloc(sizeof(pthread_t*)* parameters->n_philo);
    threads = malloc(sizeof(pthread_t)*parameters ->n_philo);
    philosophers = malloc(sizeof(t_philo*) * parameters->n_philo);
    if (!forks || !threads || !philosophers)
        return(ft_exit(1, parameters, NULL, NULL, NULL));
    //ft_print_parameters(parameters);
    ft_generate_threads(parameters, forks, threads, philosophers);
    ft_close_threads(parameters, threads);
    ft_exit(0, parameters, forks, threads, philosophers);
    return(0);
}