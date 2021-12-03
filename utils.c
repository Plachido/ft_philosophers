/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 23:06:14 by plpelleg          #+#    #+#             */
/*   Updated: 2021/12/03 19:53:19 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str, t_param *parameters)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 57 || str[i] < 48)
			ft_set_error(parameters);
		res = (res * 10) + (str[i++] - 48);
	}
	if (res * neg <= 0)
		ft_set_error(parameters);
	return (res * neg);
}

long unsigned int	ft_get_time(struct timeval tv)
{
	return ((long int)(tv.tv_sec * 1000) + (int)(tv.tv_usec / 1000));
}

void	ft_print(t_philo *philosopher, int code)
{
	struct timeval	time;

	pthread_mutex_lock(&philosopher->parameters->print);
	gettimeofday(&time, NULL);
	printf("%lu ", ft_get_time(time));
	if (code < 6)
		printf("%i ", philosopher->id + 1);
	if (code == 1)
		printf("has taken a fork");
	else if (code == 2)
		printf("is eating");
	else if (code == 3)
		printf("is sleeping");
	else if (code == 4)
		printf("is thinking");
	else if (code == 5)
		printf("died");
	else if (code == 6)
		printf("All philosophers have eaten %d times",
			philosopher->parameters->n_times_to_eat);
	printf("\n");
	if (code < 5)
		pthread_mutex_unlock(&philosopher->parameters->print);
}
