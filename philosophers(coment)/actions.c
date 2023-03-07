/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:51:40 by ghoyuelo          #+#    #+#             */
/*   Updated: 2023/03/07 11:22:18 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *ph)
{
	pthread_mutex_lock(&ph->in->forks[ph->left_fork]);
	ft_print_msg(ph, "left fork taken");
	pthread_mutex_lock(&ph->in->forks[ph->rigth_fork]);
	ft_print_msg(ph, "right fork taken");
	ft_print_msg(ph, "philo eating");
	ph->last_eat_tm = ft_time_in_ms();
	ph->nb_of_meals++;
	pthread_mutex_lock(&ph->in->eating);
	ft_check_eaten(ph);
	pthread_mutex_unlock(&ph->in->eating);
	ft_time_pass(ph, ph->in->time_to_eat);
	pthread_mutex_unlock(&ph->in->forks[ph->left_fork]);
	pthread_mutex_unlock(&ph->in->forks[ph->rigth_fork]);
	ft_print_msg(ph, "philo sleeping");
	ft_time_pass(ph, ph->in->time_to_sleep);
	ft_check_death(ph);
	ft_print_msg(ph, "philo thinking");
}
