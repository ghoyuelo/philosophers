/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:02:01 by ghoyuelo          #+#    #+#             */
/*   Updated: 2023/03/07 11:49:50 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

long	ft_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday (&time, NULL);
	return ((1000 * time.tv_sec) + (time.tv_usec / 1000));
}

void	ft_time_pass(t_philo *ph, long time)
{
	long	finish;

	finish = ft_time_in_ms() + time;
	while ((ft_time_in_ms() < finish) && !(ph->in->die))
	{
		ft_check_death(ph->in->philo);
		usleep(100);
	}
}
