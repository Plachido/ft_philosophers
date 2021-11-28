/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:26:29 by ubuntu            #+#    #+#             */
/*   Updated: 2021/11/28 22:17:07 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static void    ft_set_param(int argc, char **argv, t_param *parameters)
{
    if (argc > 4 && argc < 7) //4 parameters + 1 optional
    {
        parameters -> n_philo = ft_atoi(argv[1], parameters); //mod ft_atoi sets error to 2 if number if negative or 0
        parameters -> time_to_die = ft_atoi(argv[2], parameters);
        parameters -> time_to_eat = ft_atoi(argv[3], parameters);
        parameters -> time_to_sleep = ft_atoi(argv[4], parameters);
        if (argc == 6)
            parameters -> n_times_to_eat = ft_atoi(argv[5], parameters);
        else
            parameters -> n_times_to_eat = -1; //optional parameter, -1 if not present
    }
    else
        parameters -> error =  2;
}

t_param *ft_parse(int argc, char **argv)
{
    t_param *parameters;

    parameters = malloc(sizeof(t_param));
    if (!parameters)
    {
        ft_exit(1, parameters, NULL, NULL, NULL);
        return(NULL);
    }
    parameters -> error = 0; //Recognize errors, exit is not allowed in mandatory part
    ft_set_param(argc, argv, parameters);
    if (parameters -> error)
    {
        ft_exit(parameters -> error, parameters, NULL, NULL, NULL);
        return(NULL);
    }
    return(parameters);
}