/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:51:40 by ghoyuelo          #+#    #+#             */
/*   Updated: 2023/03/07 22:34:58 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_philo *ph)
{
	pthread_mutex_lock(&ph->in->forks[ph->left_fork]);
	ft_print_msg(ph, "has taken a fork");
	pthread_mutex_lock(&ph->in->forks[ph->rigth_fork]);
	ft_print_msg(ph, "has taken a fork");
	ft_print_msg(ph, "is eating");
	ph->last_eat_tm = ft_time_in_ms();
	ph->nb_of_meals++;
	pthread_mutex_lock(&ph->in->eating);
	ft_check_eaten(ph);
	pthread_mutex_unlock(&ph->in->eating);
	ft_time_pass(ph, ph->in->time_to_eat);
	pthread_mutex_unlock(&ph->in->forks[ph->left_fork]);
	pthread_mutex_unlock(&ph->in->forks[ph->rigth_fork]);
	if (ph->nb_of_meals == ph->in->nb_must_eats)
		return (1);
	ft_print_msg(ph, "is sleeping");
	ft_time_pass(ph, ph->in->time_to_sleep);
	ft_check_death(ph);
	ft_print_msg(ph, "is thinking");
	return (0);
}
