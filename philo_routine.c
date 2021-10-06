/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:18:17 by robrodri          #+#    #+#             */
/*   Updated: 2021/09/15 17:04:57 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

static void	action_eat(t_philo *ph)
{
	pthread_mutex_lock(&ph->prg->m_eat);
	if (ph->idx == 1)
		philo_eat(ph, ph->prg->n_philo - 1, 0);
	else
		philo_eat(ph, ph->idx - 2, ph->idx - 1);
	if (get_time_start() > ph->time_now + ph->prg->die)
		ph->alive = 0;
	ph->time_now = get_time_start();
	pthread_mutex_unlock(&ph->prg->m_eat);
}

static void	action_slp(t_philo *ph)
{
	pthread_mutex_lock(&ph->prg->m_slp);
	print_sleeping(ph);
	usleep(ph->prg->slp * 1000);
	if (get_time_start() > ph->time_now + ph->prg->die)
		ph->alive = 0;
	ph->time_now = get_time_start();
	pthread_mutex_unlock(&ph->prg->m_slp);
}

static void	action_tnk(t_philo *ph)
{
	pthread_mutex_lock(&ph->prg->m_think);
	print_thinking(ph);
	if (get_time_start() > ph->time_now + ph->prg->die)
		ph->alive = 0;
	ph->time_now = get_time_start();
	pthread_mutex_unlock(&ph->prg->m_think);
}

void	*routine(void *tid)
{
	t_philo	ph;

	ph = *(t_philo*)tid;
	if (ph.idx / 2)
		usleep(50);
	while (ph.alive)
	{
		action_eat(&ph);
		action_slp(&ph);
		action_tnk(&ph);
	}
	printf("(%d)Philo %d se ha morido\n", ph.time_now - ph.start, ph.idx);
	return (NULL);
}
