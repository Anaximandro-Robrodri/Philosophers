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
	return(m_f);
}

static void	init_philos(t_philo *ph, t_prg *prg, int i, pthread_mutex_t	*m_f)
{
	ph->prg = prg;
	ph->idx = i + 1;
	ph->m_fork = m_f;
	ph->l_fork = 0;
	ph->r_fork = 0;
	ph->alive = 1;
	ph->start = get_time_start();
	ph->time_now = ph->start;
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
	while (i < prg->n_philo)
	{
		init_philos(&ph[i], prg, i, m_f);
		pthread_create(&ph[i].t_ph, NULL, routine, &ph[i]);
		usleep(100);
		i++;
	}
	ft_join_threads(ph, prg->n_philo);
	if (ft_dead_checker(ph, prg->n_philo) == -1)
		exit(0);
}
