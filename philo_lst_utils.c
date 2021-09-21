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

static pthread_mutex_t	*init_forks(pthread_mutex_t *forks, int n, t_prg *prg)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_init(&forks[i], NULL);
		prg->forks[i] = 0;
		i++;
	}
	return(forks);
}

static void	init_philos(t_philo *ph, t_prg *prg, int i, pthread_mutex_t	*forks)
{
	ph->prg = prg;
	ph->idx = i + 1;
	ph->m_fork = forks;
}

void	create_table(t_prg *prg)
{
	t_philo			*ph;
	pthread_mutex_t	*forks;
	int				i;

	ph = malloc(sizeof(t_philo*) * prg->n_philo);
	prg->forks = malloc(sizeof(int) * prg->n_philo);
	forks = malloc(sizeof(pthread_mutex_t) * prg->n_philo);
	if (!ph || !forks || !prg->forks)
		return ;
	i = 0;
	pthread_mutex_init(&prg->m_print, NULL);
	forks = init_forks(forks, prg->n_philo, prg);
	while (i < prg->n_philo)
	{
		init_philos(&ph[i], prg, i, forks);
		pthread_create(&ph[i].t_ph, NULL, routine, &ph[i]);
		i++;
	}
}
