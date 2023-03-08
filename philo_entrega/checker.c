/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:21:02 by ghoyuelo          #+#    #+#             */
/*   Updated: 2023/03/07 22:22:48 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc < 5 || argc > 6)
	{
		printf("Error.\n Invalid number of arguments.\n");
		exit (1);
	}
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error.\n Arguments must be numbers.\n");
				exit (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_check_values(int argc, char **argv)
{
	if ((ft_atoi(argv[1])) > 200)
	{
		printf("Error.\n Philosophers must be less than 200.\n");
		exit (1);
	}
	if ((ft_atoi(argv[1])) == 0 || (ft_atoi(argv[2])) == 0
		|| (ft_atoi(argv[3])) == 0 || (ft_atoi(argv[4])) == 0)
	{
		printf("Error.\n Arguments values must be more than 0.\n");
		exit (1);
	}
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) == 0)
		{
			printf("Error.\n Arguments values must be more than 0.\n");
			exit (1);
		}
	}
}

void	ft_check_death(t_philo *ph)
{
	pthread_mutex_lock(&ph->in->deaths);
	if ((ft_time_in_ms() - ph->last_eat_tm) > ph->in->time_to_die
		&& ph->in->die == 0)
	{
		ft_print_msg(ph, "died");
		ph->in->die = 1;
	}
	pthread_mutex_unlock(&ph->in->deaths);
}

void	ft_check_eaten(t_philo *ph)
{
	int	i;

	i = 0;
	while (ph->in->nb_must_eats != 0 && i < ph->in->nb_philos
		&& (ph[i].nb_of_meals >= ph->in->nb_must_eats))
		i++;
	if (i == ph->in->nb_philos)
		ph->in->die = 1;
	usleep(200);
}
