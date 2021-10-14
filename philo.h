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
# define FORK_TAKEN GREEN"(%llu) 🍽  Philo %d has taken a fork! 🍽\n"
# define EATING YELLOW"(%llu) 🍕 Philo %d is eating 🍕\n"
# define SLEEPING CYAN"(%llu) 😴 Philo %d is sleeping 😴\n"
# define THINKING RESET"(%llu) 🧠 Philo %d is thinking 🧠\n"
# define DAMOCLES_SWORD RED"(%llu) ☠️  Philo %d has died ☠️\n"
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_prg
{
	int				n_philo;
	uint64_t		die;
	uint64_t		eat;
	uint64_t		slp;
	uint64_t		n_eat;
	int				*forks;
	uint64_t		start;
	bool			running;
	pthread_mutex_t	m_print;
}	t_prg ;

typedef struct s_philo
{
	bool			alive;
	int				idx;
	uint64_t		last_eat;
	uint64_t		count;
	t_prg			*prg;
	pthread_t		t_ph;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	*m_fork;
}	t_philo ;

int			ft_is_space(char a);
int			ft_is_sign(char a);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
int			ft_error_control(int i, char **argv);
void		create_table(t_prg *prg);
void		*routine(void *tid);
uint64_t	get_time_start(void);
void		ft_dead_checker(t_philo *ph, int n);
int			is_he_alive(t_philo *ph);
void		philo_eat(t_philo *ph, int left, int right);
void		ft_usleep(uint64_t time);
void		print_action(t_philo *ph, char *msg, uint64_t time);
void		print_dead(t_philo *ph);
void		print_success(t_philo *ph);
#endif
