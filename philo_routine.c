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

static void	odd_philo(t_philo *ph)
{
	if (ph->prg->forks[ph->idx - 1])
	{
		pthread_mutex_lock(&ph->m_fork[ph->idx - 1]);
		ph->prg->forks[ph->idx - 1] = 0;
		ph->r_fork = 1;
		print_fork(ph);
	}
	if (ph->idx == 1)
	{
		if (ph->prg->forks[ph->prg->n_philo - 1])
		{
			pthread_mutex_lock(&ph->m_fork[ph->prg->n_philo - 1]);
			ph->prg->forks[ph->prg->n_philo - 1] = 0;
			ph->l_fork = 1;
			print_fork(ph);
		}
	}
	else
	{
		if (ph->prg->forks[ph->idx - 2])
		{
			pthread_mutex_lock(&ph->m_fork[ph->idx - 2]);
			ph->prg->forks[ph->idx - 2] = 0;
			ph->l_fork = 1;
			print_fork(ph);
		}
	}
	if (ph->l_fork && ph->r_fork)
	{
		print_eating(ph);
		usleep(ph->prg->eat);
		if (ph->idx == 1)
		{
			ph->prg->forks[ph->idx - 1] = 1;
			ph->prg->forks[ph->prg->n_philo - 1] = 1;
			ph->l_fork = 0;
			ph->r_fork = 0;
			pthread_mutex_unlock(&ph->m_fork[ph->idx - 1]);
			pthread_mutex_unlock(&ph->m_fork[ph->prg->n_philo - 1]);
		}
		else
		{
			ph->prg->forks[ph->idx - 1] = 1;
			ph->prg->forks[ph->idx - 2] = 1;
			ph->l_fork = 0;
			ph->r_fork = 0;
			pthread_mutex_unlock(&ph->m_fork[ph->idx - 1]);
			pthread_mutex_unlock(&ph->m_fork[ph->idx - 2]);
		}
	}
}

static void	even_philo(t_philo *ph)
{
	if (ph->prg->forks[ph->idx - 1])
	{
		pthread_mutex_lock(&ph->m_fork[ph->idx - 1]);
		ph->prg->forks[ph->idx - 1] = 0;
		ph->r_fork = 1;
		print_fork(ph);
	}
	if (ph->prg->forks[ph->idx - 2])
	{
		pthread_mutex_lock(&ph->m_fork[ph->idx - 2]);
		ph->prg->forks[ph->idx - 2] = 0;
		ph->l_fork = 1;
		print_fork(ph);
	}
	if (ph->l_fork && ph->r_fork)
	{
		print_eating(ph);
		usleep(ph->prg->eat);
		ph->prg->forks[ph->idx - 1] = 1;
		ph->prg->forks[ph->idx - 2] = 1;
		ph->l_fork = 0;
		ph->r_fork = 0;
		pthread_mutex_unlock(&ph->m_fork[ph->idx - 1]);
		pthread_mutex_unlock(&ph->m_fork[ph->idx - 2]);
	}
}

void	*routine(void *tid)
{
	t_philo	ph;

	ph = *(t_philo*)tid;
	if (ph.idx / 2)
		usleep(50);
	while (ph.sts.alive)
	{
		if (ph.idx % 2)
			odd_philo(&ph);
		else
			even_philo(&ph);
	}
	return (NULL);
}
