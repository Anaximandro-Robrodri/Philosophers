/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:18:12 by robrodri          #+#    #+#             */
/*   Updated: 2021/09/11 16:18:13 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*static void	ft_join_threads(t_philo *ph, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_join(ph[i].t_ph, NULL);
		i++;
	}
}*/

static void	ft_destroy_mutex(pthread_mutex_t *m_f, t_prg *prg, t_philo *ph)
{
	int	i;

	i = 0;
	while (i < prg->n_philo)
	{
		pthread_mutex_destroy(&m_f[i]);
		pthread_mutex_destroy(&ph[i].m_dead);
		i++;
	}
	pthread_mutex_destroy(&prg->m_print);
	free(prg->forks);
	free(m_f);
}

static pthread_mutex_t	*init_forks(pthread_mutex_t *m_f, int n, t_prg *prg)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_init(&m_f[i], NULL);
		prg->forks[i] = 1;
		i++;
	}
	pthread_mutex_init(&prg->m_print, NULL);
	prg->start = get_time_start();
	prg->running = 1;
	return (m_f);
}

static void	ft_assign_forks(t_philo *ph, pthread_mutex_t *m_f)
{
	if (ph->idx == 1)
	{
		ph->right = &m_f[ph->idx - 1];
		ph->left = &m_f[ph->prg->n_philo - 1];
	}
	else
	{
		ph->right = &m_f[ph->idx - 1];
		ph->left = &m_f[ph->idx - 2];
	}
}

static void	init_philos(t_philo *ph, t_prg *prg,pthread_mutex_t	*m_f)
{
	int	i;

	i = 0;
	while (i < prg->n_philo)
	{
		pthread_mutex_init(&ph->m_dead, NULL);
		ph[i].prg = prg;
		ph[i].last_eat = prg->start;
		ph[i].idx = i + 1;
		ph[i].alive = 1;
		ph[i].count = 0;
		ph[i].full = 0;
		ft_assign_forks(&ph[i], m_f);
		i++;
	}
}

void	create_table(t_prg *prg)
{
	t_philo			*ph;
	pthread_mutex_t	*m_f;
	int				i;

	ph = malloc(sizeof(t_philo) * prg->n_philo);
	prg->forks = malloc(sizeof(int) * prg->n_philo);
	m_f = malloc(sizeof(pthread_mutex_t) * prg->n_philo);
	if (!ph || !m_f || !prg->forks)
		return ;
	m_f = init_forks(m_f, prg->n_philo, prg);
	i = 0;
	init_philos(ph, prg, m_f);
	while (i < prg->n_philo)
	{
		pthread_create(&ph[i].t_ph, NULL, routine, &ph[i]);
		i++;
//		usleep(100);
	}
	ft_dead_checker(ph, prg->n_philo);
//	ft_join_threads(ph, prg->n_philo);
	ft_destroy_mutex(m_f, prg, ph);
	free(ph);
	return ;
}
