# include "../header/philo.h"
#include <stdio.h>
void    ft_print_parameters(t_param *parameters)
{
    printf("N_PHILO:        %d\n", parameters->n_philo);
    printf("TIME TO DIE:    %d\n", parameters ->time_to_die);
    printf("TIME TO EAT:    %d\n", parameters -> time_to_eat);
    printf("TIME TO SLEEP:  %d\n", parameters->time_to_sleep);
    printf("N_TIMES TO EAT: %d\n", parameters->n_times_to_eat);
}