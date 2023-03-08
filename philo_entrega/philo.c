/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:39:49 by ghoyuelo          #+#    #+#             */
/*   Updated: 2023/03/07 22:37:03 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy(t_data *in)
{
	int	i;

	i = 0;
	while (i < in->nb_philos)
	{
		pthread_mutex_destroy(&in->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&in->eating);
	pthread_mutex_destroy(&in->print);
	pthread_mutex_destroy(&in->deaths);
}

void	*ft_routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *) arg;
	if (ph->in->nb_philos == 1)
	{
		ft_print_msg(ph, "has taken fork");
		ft_time_pass(ph, ph->in->time_to_die);
		ft_print_msg(ph, "died");
		pthread_mutex_unlock(&ph->in->forks[ph->left_fork]);
		return (NULL);
	}
	if (ph->id % 2 == 0)
		usleep(1000);
	while (!ph->in->die && !ph->in->all_eat)
	{
		ft_check_death(ph);
		ft_check_eaten(ph);
		if (ft_eat(ph) == 1)
			break ;
		ft_check_death(ph);
	}
	return (NULL);
}

void	ft_begin(t_data *in)
{
	int		i;
	t_philo	*ph;

	i = 0;
	ph = in->philo;
	in->tm_born = ft_time_in_ms();
	while (i < in->nb_philos)
	{
		pthread_create(&ph[i].ph_thread, NULL, ft_routine, &(ph[i]));
		ph[i].last_eat_tm = ft_time_in_ms();
		i++;
	}
	i = 0;
	while (i < in->nb_philos)
	{
		pthread_join(ph[i].ph_thread, NULL);
		i++;
	}
	ft_destroy(in);
}

int	main(int argc, char **argv)
{
	t_data	in;

	ft_check_args(argc, argv);
	ft_check_values(argc, argv);
	ft_init_stdata(argc, argv, &in);
	ft_init_stphilo(&in);
	ft_init_mutex(&in);
	ft_begin(&in);
	free(in.philo);
	free(in.forks);
	return (0);
}
