/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:55:09 by plpelleg          #+#    #+#             */
/*   Updated: 2021/11/28 22:24:31 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philo.h"

void    ft_set_error(int code, t_param *parameters)
{
    parameters -> error = code;
}

static void    ft_free(t_param *parameters, pthread_mutex_t **forks, pthread_t *threads, t_philo **philosophers)
{
    int i;
    if (forks)
        free(forks);
    if (threads)
        free(threads);
    if (philosophers)
    {
        i = -1;
        while(++i < parameters->n_philo)
            free(philosophers[i]);
        free(philosophers);
    }
    if(parameters)
        free(parameters);
}

int    ft_exit(int code, t_param *parameters, pthread_mutex_t **forks, pthread_t *threads,t_philo **philosophers)
{
    if (!code)
        write(1, "THE END", 8);
    else if (code == 1)
        write(1, "MALLOC ERROR", 13);
    else if (code == 2)
        write(1, "PARAMETER ERROR", 16);
    write(1, "\n", 2);
    ft_free(parameters, forks, threads, philosophers);
    return(0);
}
