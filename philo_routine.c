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
	if (ph->alive)
	{
		if (ph->idx == 1)
			philo_eat(ph, ph->prg->n_philo - 1, 0);
		else
			philo_eat(ph, ph->idx - 2, ph->idx - 1);
	}
//	is_he_alive(ph);
//	ph->time_now = get_time_start();
	pthread_mutex_unlock(&ph->prg->m_eat);
}

static void	action_slp(t_philo *ph)
{
	pthread_mutex_lock(&ph->prg->m_slp);
	if (ph->alive)
	{
		print_sleeping(ph);
		usleep(ph->prg->slp * 1000);
	}
//	is_he_alive(ph);
//	ph->time_now = get_time_start();
	pthread_mutex_unlock(&ph->prg->m_slp);
}

static void	action_tnk(t_philo *ph)
{
	pthread_mutex_lock(&ph->prg->m_think);
	if (ph->alive)
		print_thinking(ph);
//	is_he_alive(ph);
//	ph->time_now = get_time_start();
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
		if (!is_he_alive(&ph))
			break ;
		action_eat(&ph);
		if (!is_he_alive(&ph))
			break ;
		action_slp(&ph);
		if (!is_he_alive(&ph))
			break ;
		action_tnk(&ph);
	}
	if (!ph.alive)
		print_dead(&ph);
	return (NULL);
}
