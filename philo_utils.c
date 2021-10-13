/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:18:23 by robrodri          #+#    #+#             */
/*   Updated: 2021/09/11 16:18:25 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_space(char a)
{
	if ((a >= 9 && a <= 13) || a == ' ')
		return (1);
	return (0);
}

int	ft_is_sign(char a)
{
	if (a == '+')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if ((c < 48) || (c > 57))
	{
		return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	nb;
	int				sign;

	i = 0;
	nb = 0;
	sign = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' \
			|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = (nb * 10) + (str[i++] - '0');
	if (nb > 2147483647 && !sign)
		return (-1);
	else if (nb > 2147483648 && sign)
		return (0);
	else if (sign)
		return ((int)nb * -1);
	return ((int) nb);
}

int	ft_error_control(int i, char **argv)
{
	int	pos;

	pos = 0;
	while (argv[i][pos])
	{
		if (!ft_isdigit(argv[i][pos]) && !ft_is_space(argv[i][pos])
				&& !ft_is_sign(argv[i][pos]))
			return (0);
		if (ft_is_sign(argv[i][pos]))
			if (!ft_isdigit(argv[i][pos + 1]) || !argv[i][pos + 1])
				return (0);
		pos++;
	}
	return (1);
}
