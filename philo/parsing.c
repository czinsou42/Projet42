/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:45:11 by czinsou           #+#    #+#             */
/*   Updated: 2025/12/04 17:22:38 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid_number(const char *str)
{
	int	i;
	int	digit_len;

	i = 0;
	digit_len = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (error_exit("Only positive value is accepted"));
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit_len++;
		else
			return (error_exit("Only digit is accepted"));
		i++;
	}
	if (digit_len > 10)
		return (error_exit("The nombers is too long"));
	return (1);
}

long	ft_atol(const char *str)
{
	long	i;
	long	result;

	i = 0;
	result = 0;
	if (!str || !*str)
		return (error_exit("Empty Argument"));
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (is_valid_number(str + i) == -1)
		return (error_exit("Invalid Input"));
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > INT_MAX)
			return (error_exit("The digit is too big"));
		i++;
	}
	return (result);
}

int	parse_arg(t_table *table, char **argv)
{
	table->philo_nbr = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (table->philo_nbr == -1 || table->time_to_die == -1
		|| table->time_to_eat == -1 || table->time_to_sleep == -1)
		return (-1);
	if (table->time_to_die < 60 || table->time_to_eat < 60
		|| table->time_to_sleep < 60)
		return (error_exit("The timestamps must be major than 60ms"));
	if (argv[5])
	{
		table->nbr_limit_meals = ft_atol(argv[5]);
		if (table->nbr_limit_meals == -1)
			return (-1);
	}
	else
		table->nbr_limit_meals = -1;
	return (0);
}
