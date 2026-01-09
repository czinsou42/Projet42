/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:08:36 by czinsou           #+#    #+#             */
/*   Updated: 2026/01/09 15:40:09 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	all_full(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		if (!table->philos[i].full)
			return (false);
		i++;
	}
	return (true);
}

void	check_philos(t_table *table)
{
	int		i;
	long	now;

	i = 0;
	while (i < table->philo_nbr)
	{
		if (safe_mutex(&table->table_mutex, LOCK) == -1)
			return ;
		now = gettime();
		if (((now - table->philos[i].last_meals_time) > table->time_to_die)
			&& !table->end_simulation)
		{
			print_death(&table->philos[i], "is died");
			table->end_simulation = true;
			safe_mutex(&table->table_mutex, UNLOCK);
			return ;
		}
		if (table->nbr_limit_meals > 0
			&& table->philos[i].nbr_meals >= table->nbr_limit_meals)
			table->philos[i].full = true;
		safe_mutex(&table->table_mutex, UNLOCK);
		i++;
	}
}

void	*routine(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		if (safe_mutex(&table->table_mutex, LOCK) == -1)
			return (NULL);
		if (table->end_simulation)
			return ((safe_mutex(&table->table_mutex, UNLOCK)), NULL);
		safe_mutex(&table->table_mutex, UNLOCK);
		check_philos(table);
		if ((table->nbr_limit_meals > 0) && all_full(table))
		{
			if (safe_mutex(&table->table_mutex, LOCK) != -1)
			{
				table->end_simulation = true;
				safe_mutex(&table->table_mutex, UNLOCK);
				return (NULL);
			}
		}
		my_usleep(1, table);
	}
	return (NULL);
}
