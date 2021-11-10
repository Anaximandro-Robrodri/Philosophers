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
# define FORK_TAKEN "(%llu) Philo %d has taken a fork\n"
# define EATING "(%llu) Philo %d is eating\n"
# define SLEEPING "(%llu) Philo %d is sleeping\n"
# define THINKING "(%llu) Philo %d is thinking\n"
# define DAMOCLES_SWORD "(%lu) Philo %d has died\n"
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_prg
{
	int				n_philo;
	int				die;
	int				eat;
	int				slp;
	int				n_eat;
	int				*forks;
	u_int64_t		start;
	int				running;
	pthread_mutex_t	m_print;
}	t_prg;

typedef struct s_philo
{
	int				alive;
	int				idx;
	u_int64_t		last_eat;
	int				count;
	int				full;
	t_prg			*prg;
	pthread_t		t_ph;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
}	t_philo;

int			ft_is_space(char a);
int			ft_is_sign(char a);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
int			ft_error_control(int i, char **argv);
void		create_table(t_prg *prg);
void		*routine(void *tid);
u_int64_t	get_time_start(void);
void		ft_dead_checker(t_philo *ph, int n);
int			is_he_alive(t_philo *ph);
void		action_eat(t_philo *ph);
void		ft_usleep(u_int64_t time);
void		print_action(t_philo *ph, char *msg);
void		end_program(t_philo *ph);
#endif
