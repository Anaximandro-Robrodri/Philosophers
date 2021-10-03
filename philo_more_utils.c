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

# include "philo.h"

int	ft_dead_checker(t_philo *ph, int n)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < n)
		{
			if (!ph[i].alive)
				return (-1);
			i++;
		}
	}
}

void	ft_join_threads(t_philo *ph, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_join(ph[i].t_ph, NULL);
		i++;
	}
}

int	get_time_start(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	odd_philo(t_philo *ph)
{
	if (ph->prg->forks[ph->idx - 1])
	{
		print_fork(ph);
		pthread_mutex_lock(&ph->m_fork[ph->idx - 1]);
		ph->prg->forks[ph->idx - 1] = 0;
		ph->r_fork = 1;
	}
	if (ph->prg->forks[ph->idx - 2])
	{
		print_fork(ph);
		pthread_mutex_lock(&ph->m_fork[ph->idx - 2]);
		ph->prg->forks[ph->idx - 2] = 0;
		ph->l_fork = 1;
	}
	if (ph->r_fork && ph->l_fork)
	{
		print_eating(ph);
		usleep(ph->prg->eat * 1000);
		ph->prg->forks[ph->idx - 1] = 1;
		ph->prg->forks[ph->idx - 2] = 1;
		ph->r_fork = 0;
		ph->l_fork = 0;
		pthread_mutex_unlock(&ph->m_fork[ph->idx - 1]);
		pthread_mutex_unlock(&ph->m_fork[ph->idx - 2]);
	}
}

void	even_philo(t_philo *ph, int i, int j)
{
	if (ph->prg->forks[j])
	{
		print_fork(ph);
		pthread_mutex_lock(&ph->m_fork[j]);
		ph->prg->forks[j] = 0;
		ph->r_fork = 1;
	}
	if (ph->prg->forks[i])
	{
		print_fork(ph);
		pthread_mutex_lock(&ph->m_fork[i]);
		ph->prg->forks[i] = 0;
		ph->l_fork = 1;
	}
	if (ph->r_fork && ph->l_fork)
	{
		print_eating(ph);
		usleep(ph->prg->eat * 1000);
		ph->prg->forks[i] = 1;
		ph->prg->forks[j] = 1;
		ph->r_fork = 0;
		ph->l_fork = 0;
		pthread_mutex_unlock(&ph->m_fork[j]);
		pthread_mutex_unlock(&ph->m_fork[i]);
	}
}
