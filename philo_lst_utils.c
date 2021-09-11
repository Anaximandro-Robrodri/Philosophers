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

void	create_table(t_prg *prg)
{
	printf("N philos %d\n", prg->n_philo);
	printf("Time to die %d\n", prg->die);
	printf("Time to sleep %d\n", prg->slp);
	printf("Time to eat %d\n", prg->eat);
	printf("N eat %d\n", prg->n_eat);
}
