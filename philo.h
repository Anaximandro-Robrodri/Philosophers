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
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"
# define YELLOW "\033[0;33m"
# define FORK_TAKEN GREEN"(%d) 🍽  Philo %d has taken a fork! 🍽\n"
# define EATING YELLOW"(%d) 🍕 Philo %d is eating 🍕\n"
# define SLEEPING CYAN"(%d) 😴 Philo %d is sleeping 😴\n"
# define THINKING RESET"(%d) 🧠 Philo %d is thinking 🧠\n"
# define DAMOCLES_SWORD RED"(%d) ☠️  Philo %d has died ☠️\n"
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

/* Parametros de ms min 60 ms */

/* En este guardamos los datos comunes a cada filosofo*/
typedef struct s_prg
{
	int				n_philo;
	int				die;
	int				eat;
	int				slp;
	int				n_eat;
	int				*forks;
	int				start;
	int				running;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	m_eat;
}	t_prg ;

/*Hacemos n filosofos cada uno con idx*/
typedef struct s_philo
{
	int				alive;
	int				has_eaten;
	int				idx;
	int				thk;
	int				r_fork;
	int				l_fork;
	int				last_eat;
	t_prg			*prg;
	pthread_t		t_ph;
	pthread_mutex_t	*m_fork;
}	t_philo ;

/* Just parsing and stuff */
void	ft_error(void);
int		ft_is_space(char a);
int		ft_is_sign(char a);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_error_control(int i, char **argv);
/* Important functions for philos */
void	create_table(t_prg *prg);
void	*routine(void *tid);
int		get_time_start(void);
int		ft_dead_checker(t_philo *ph, int n);
int		is_he_alive(t_philo *ph);
void	ft_join_threads(t_philo *ph, int n);
void	philo_eat(t_philo *ph, int left, int right);
void	ft_usleep(int time);
/* Print messages functions */
void	print_action(t_philo *ph, char *msg, int time);
void	print_dead(t_philo *ph);
#endif
