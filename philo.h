/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:18:05 by robrodri          #+#    #+#             */
/*   Updated: 2021/09/11 16:18:07 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define MAX_PHILO 200
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

/* En este guardamos los datos comunes a cada filosofo*/
typedef struct s_prg
{
	int				n_philo;
	int				die;
	int				eat;
	int				slp;
	int				n_eat;
	int				*forks;
	pthread_mutex_t	m_print;
}	t_prg ;

/*Hacemos n filosofos cada uno con idx*/
typedef struct s_philo
{
	int				alive;
	int				has_eaten;
	int				idx;
	int				l_fork;
	int				r_fork;
	int				start;
	t_prg			*prg;
	pthread_t		t_ph;
	pthread_mutex_t	*m_fork;
}	t_philo ;

/*Just parsing and stuff*/
void	ft_error(void);
int		ft_is_space(char a);
int		ft_is_sign(char a);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_error_control(int i, char **argv);
/*Important functions for philos*/
void	create_table(t_prg *prg);
void	*routine(void *tid);
int		get_time_start(void);
int		ft_dead_checker(t_philo *ph, int n);
/* Print messages functions*/
void	print_fork(t_philo *ph);
void	print_eating(t_philo *ph);
void	print_sleeping(t_philo *ph);
void	print_thinking(t_philo *ph);

#endif
