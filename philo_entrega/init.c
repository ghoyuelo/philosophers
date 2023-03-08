/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:25:15 by ghoyuelo          #+#    #+#             */
/*   Updated: 2023/03/07 11:42:32 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_stdata(int argc, char **argv, t_data *in)
{
	in->die = 0;
	in->all_eat = 0;
	in->nb_philos = ft_atoi(argv[1]);
	in->time_to_die = ft_atoi(argv[2]);
	in->time_to_eat = ft_atoi(argv[3]);
	in->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		in->nb_must_eats = ft_atoi(argv[5]);
	else
		in->nb_must_eats = 0;
	in->philo = malloc(sizeof(t_data) * in->nb_philos);
	in->forks = malloc(sizeof(t_data) * in->nb_philos);
}

void	ft_init_stphilo(t_data *in)
{
	int	i;

	i = 0;
	while (i <= in->nb_philos - 1)
	{
		in->philo[i].id = i + 1;
		in->philo[i].last_eat_tm = 0;
		in->philo[i].nb_of_meals = 0;
		in->philo[i].rigth_fork = i + 1;
		in->philo[i].in = in;
		if (i == 0)
			in->philo[i].left_fork = in->nb_philos;
		else
			in->philo[i].left_fork = i;
		i++;
	}
}

void	ft_init_mutex(t_data *in)
{
	int	i;

	i = 0;
	pthread_mutex_init(&in->eating, NULL);
	pthread_mutex_init(&in->print, NULL);
	pthread_mutex_init(&in->deaths, NULL);
	while (i <= in->nb_philos - 1)
	{
		pthread_mutex_init(&in->forks[i], NULL);
		i++;
	}
}
