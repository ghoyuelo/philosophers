/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:01:30 by ghoyuelo          #+#    #+#             */
/*   Updated: 2023/03/07 22:33:35 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				rigth_fork;
	int				nb_of_meals;
	long			last_eat_tm;
	pthread_t		ph_thread;
	struct s_data	*in;
}	t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eats;
	long			nb_eats;
	long			tm_born;
	int				die;
	int				all_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	deaths;
	pthread_mutex_t	eating;
	t_philo			*philo;
}	t_data;

/*********** Checker **********/
void	ft_check_args(int argc, char **argv);
void	ft_check_values(int argc, char **argv);
void	ft_check_death(t_philo *ph);
void	ft_check_eaten(t_philo *ph);

/*********** Init *************/
void	ft_init_stdata(int argc, char **argv, t_data *in);
void	ft_init_stphilo(t_data *in);
void	ft_init_mutex(t_data *in);

/*********** Actions **********/
int		ft_eat(t_philo *ph);

/*********** Utils ************/
int		ft_atoi(char *str);
void	ft_print_msg(t_philo *ph, char *msg);

/*********** Time *************/
long	ft_time_in_ms(void);
void	ft_time_pass(t_philo *ph, long time);

#endif