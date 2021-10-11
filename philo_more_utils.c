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

void	ft_usleep(int time)
{
	int	timer;

	timer = get_time_start();
	while ((get_time_start() - timer) < time)
		usleep(1000);
}

int	ft_dead_checker(t_philo *ph, int n)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < n)
		{
			if (!ph[i].alive)
			{
				ph->prg->running = 0;
				print_dead(&ph[i]);
				return (-1);
			}
			i++;
		}
	}
	return (0);
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
	pthread_mutex_lock(&ph->prg->m_dead);
	if (get_time_start() > ph->last_eat + ph->prg->die)
	{
		ph->alive = 0;
		pthread_mutex_unlock(&ph->prg->m_dead);
		return (0);
	}
	pthread_mutex_unlock(&ph->prg->m_dead);
	return (1);
}

void	philo_eat(t_philo *ph, int left, int right)
{
	pthread_mutex_lock(&ph->m_fork[right]);
	print_action(ph, FORK_TAKEN, get_time_start() - ph->prg->start);
	ph->prg->forks[right] = 0;
	pthread_mutex_lock(&ph->m_fork[left]);
	print_action(ph, FORK_TAKEN, get_time_start() - ph->prg->start);
	ph->prg->forks[left] = 0;
	if (!ph->prg->forks[right] && !ph->prg->forks[left])
	{
		ph->last_eat = get_time_start();
		print_action(ph, EATING, ph->last_eat - ph->prg->start);
		ft_usleep(ph->prg->eat);
		ph->prg->forks[left] = 1;
		ph->prg->forks[right] = 1;
		ph->has_eaten = 1;
		pthread_mutex_unlock(&ph->m_fork[right]);
		pthread_mutex_unlock(&ph->m_fork[left]);
	}
}
