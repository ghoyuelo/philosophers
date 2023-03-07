/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:01:30 by ghoyuelo          #+#    #+#             */
/*   Updated: 2023/03/07 11:49:14 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo //estcutura para cada filosofo
{
	int				id;//nº identificador de cada filosofo
	int				left_fork;
	int				rigth_fork;
	int				nb_of_meals;//nº de comidas
	long			last_eat_tm;//tiempo transcurrido desde la ultima comida
	pthread_t		ph_thread;//hilo
	struct s_data	*in; //puntero a la estructura data
}	t_philo;

typedef struct s_data //estructura de entrada de datos
{
	int				nb_philos;//nº de filosofos
	int				time_to_die;//tiempo que debe transcurrir para que un ph muera
	int				time_to_eat;//tiempo que que va tardar en terminar de comer 
	int				time_to_sleep;//tiempo que cada ph duerme
	int				nb_must_eats;//(OPCIONAL)si todos los ph comen n veces el programa se detendra
	long			nb_eats;//
	long			tm_born;//Momento en el que se crean los hilos
	int				die;// = 0; = 1 -> un filosofo ha muerto, el programa se para
	int				all_eat;//todos han comido ya
	pthread_mutex_t	*forks;//bloqueo para tenedores (array)
	pthread_mutex_t	print;//bloqueo printear
	pthread_mutex_t	deaths;//bloqueo para muerte
	pthread_mutex_t	eating;// bloqueo para comer
	t_philo			*philo;//array de tipo (t_philo) donde guardo las variables de cada philo
}	t_data;

/*********** Checker **********/
void	ft_check_args(int argc, char **argv);
void	ft_check_values(char **argv);
void	ft_check_death(t_philo *ph);
void	ft_check_eaten(t_philo *ph);

/*********** Init *************/
void	ft_init_stdata(int argc, char **argv, t_data *in);
void	ft_init_stphilo(t_data *in);
void	ft_init_mutex(t_data *in);

/*********** Actions **********/
void	ft_eat(t_philo *ph);

/*********** Utils ************/
int		ft_atoi(char *str);
void	ft_print_msg(t_philo *ph, char *msg);

/*********** Time *************/
long	ft_time_in_ms(void);
void	ft_time_pass(t_philo *ph, long time);

#endif