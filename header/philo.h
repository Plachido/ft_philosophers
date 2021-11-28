/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:32:33 by plpelleg          #+#    #+#             */
/*   Updated: 2021/11/28 22:16:14 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_param
{
    int n_philo;
    int time_to_die;    
    int time_to_eat;
    int time_to_sleep;
    int n_times_to_eat;
    int error;
}       t_param;

typedef struct s_philo
{
    int id;
    t_param *parameters;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
}   t_philo;

//parsing/ft_parse.c
t_param *ft_parse(int argc, char **argv);

//utils/ft_atoi.c
int ft_atoi(char *str, t_param *parameters);

//end/ft_exit
void    ft_set_error(int code, t_param *parameters);
int    ft_exit(int code, t_param *parameters, pthread_mutex_t **forks, pthread_t *threads,t_philo **philosophers);


void    *routine(void *args);





void    ft_generate_threads(t_param *parameters, pthread_mutex_t **forks, pthread_t *threads, t_philo **philosophers);


void ft_close_threads(t_param *parameters, pthread_t *threads);


//temp
void    ft_print_parameters(t_param *parameters);
#endif