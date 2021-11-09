/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_more_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 10:51:05 by robrodri          #+#    #+#             */
/*   Updated: 2021/10/02 10:51:06 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philo_full(t_philo *ph, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (ph[i].count >= ph[i].prg->n_eat)
			j++;
		i++;
	}
	if (j == ph->prg->n_philo)
		return (1);
	return (0);
}

void	ft_dead_checker(t_philo *ph, int n)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < n)
		{
			if (!is_he_alive(&ph[i]))
			{
				end_program(&ph[i]);
				pthread_detach(ph[i].t_ph);
				return ;
			}
			if (ph->prg->n_eat > 0)
			{
				if (check_philo_full(ph, n))
				{
					ph->prg->running = 0;
					return ;
				}
			}
			i++;
		}
	}
}

u_int64_t	get_time_start(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((u_int64_t)(time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	is_he_alive(t_philo *ph)
{
	if (get_time_start() > ph->last_eat + ph->prg->die)
	{
		ph->alive = 0;
		return (0);
	}
	return (1);
}

void	action_eat(t_philo *ph)
{
	pthread_mutex_lock(ph->right);
	print_action(ph, FORK_TAKEN);
	pthread_mutex_lock(ph->left);
	print_action(ph, FORK_TAKEN);
	pthread_mutex_lock(&ph->m_dead);
	print_action(ph, EATING);
	ph->last_eat = get_time_start();
	ft_usleep(ph->prg->eat);
	if (ph->prg->n_eat > 0)
		ph->count++;
	pthread_mutex_unlock(ph->right);
	pthread_mutex_unlock(ph->left);
	pthread_mutex_unlock(&ph->m_dead);
}
