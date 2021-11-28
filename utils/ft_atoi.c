/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:52:18 by plpelleg          #+#    #+#             */
/*   Updated: 2021/11/27 18:45:37 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/philo.h"

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
			ft_set_error(2, parameters);
		res = (res * 10) + (str[i++] - 48);
	}
	if (res * neg <= 0)
		ft_set_error(2, parameters);
	return (res * neg);
}