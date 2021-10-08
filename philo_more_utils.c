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
			ph->prg->dead = get_time_start() - ph->prg->now + ph->prg->die;
			if (!ph[i].alive)
			{
				print_dead(&ph[i]);
				return (-1);
			}
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

int	is_he_alive(t_philo *ph)
{
	if (get_time_start() > ph->prg->now + ph->prg->die)
	{
		if (ph->alive == 1)
		{
			ph->alive = 0;
			ph->prg->now = get_time_start();
		}
		return (0);
	}
	ph->prg->now = get_time_start();
	return (1);
}

void	philo_eat(t_philo *ph, int left, int right)
{
	if (ph->prg->forks[right])
	{
		print_fork(ph);
		pthread_mutex_lock(&ph->m_fork[right]);
		ph->prg->forks[right] = 0;
		ph->r_fork = 1;
	}
	if (ph->prg->forks[left])
	{
		print_fork(ph);
		pthread_mutex_lock(&ph->m_fork[left]);
		ph->prg->forks[left] = 0;
		ph->l_fork = 1;
	}
	if (ph->r_fork && ph->l_fork)
	{
		print_eating(ph);
		usleep(ph->prg->eat * 1000);
		ph->prg->forks[left] = 1;
		ph->prg->forks[right] = 1;
		ph->r_fork = 0;
		ph->l_fork = 0;
		pthread_mutex_unlock(&ph->m_fork[right]);
		pthread_mutex_unlock(&ph->m_fork[left]);
	}
}
