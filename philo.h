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

typedef struct s_philo
{
	int				has_eaten;
	int				idx;
	struct s_prg	*prg;
	pthread_t		t_ph;
}	t_philo;

typedef struct s_prg
{
	int				n_philo;
	int				die;
	int				eat;
	int				slp;
	int				n_eat;
	t_philo			*philo;
}	t_prg;

void	ft_error(void);
int		ft_is_space(char a);
int		ft_is_sign(char a);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_error_control(int i, char **argv);
void	create_table(t_prg *prg);
void	*routine(void *tid);

#endif
