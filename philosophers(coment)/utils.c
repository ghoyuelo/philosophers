/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:07:26 by ghoyuelo          #+#    #+#             */
/*   Updated: 2023/03/07 11:43:07 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	return (num);
}

void	ft_print_msg(t_philo *ph, char *msg)
{
	pthread_mutex_lock(&ph->in->print);
	if (!ph->in->die)
		printf("%ld\t\t %d \t%s\n",
			ft_time_in_ms() - ph->in->tm_born, ph->id, msg);
	pthread_mutex_unlock(&ph->in->print);
}
