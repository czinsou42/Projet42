/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:15:45 by czinsou           #+#    #+#             */
/*   Updated: 2025/12/04 17:20:04 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_forks(t_philo *philo, t_fork *forks, int philo_position)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	philo->first_fork = &forks[(philo_position + 1) % philo_nbr];
	philo->second_fork = &forks[philo_position];
	if (philo->id % 2)
	{
		usleep(1000);
		philo->first_fork = &forks[philo_position];
		philo->second_fork = &forks[(philo_position + 1) % philo_nbr];
	}
}

void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < table->philo_nbr)
	{
		philo = &table->philos[i];
		philo->id = i + 1;
		philo->full = false;
		philo->nbr_meals = 0;
		philo->table = table;
		philo->last_meals_time = gettime();
		assign_forks(philo, table->forks, i);
		i++;
	}
}

int	data_init(t_table *table)
{
	int	i;

	i = 0;
	table->end_simulation = false;
	table->philos = safe_malloc(sizeof(t_philo) * (table->philo_nbr));
	if (!table->philos)
		return (-1);
	table->forks = safe_malloc(sizeof(t_fork) * table->philo_nbr);
	if (!table->forks)
		return (-1);
	if (safe_mutex(&table->table_mutex, INIT) == -1)
		return (-1);
	while (i < table->philo_nbr)
	{
		if (safe_mutex(&table->forks[i].fork, INIT) == -1)
			return (-1);
		table->forks[i].fork_id = i;
		i++;
	}
	philo_init(table);
	return (0);
}
