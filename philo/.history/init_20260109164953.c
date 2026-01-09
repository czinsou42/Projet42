/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:15:45 by czinsou           #+#    #+#             */
/*   Updated: 2026/01/09 16:49:53 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_forks(t_philo *philo, t_fork *forks, int philo_position)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	if (philo->id % 2)
	{
		philo->first_fork = &forks[philo_position];
		philo->second_fork = &forks[(philo_position + 1) % philo_nbr];
	}
	else
	{
		philo->first_fork = &forks[(philo_position + 1) % philo_nbr];
		philo->second_fork = &forks[philo_position];
	}
}

void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = &table->philos;
	while (i < table->philo_nbr)
	{
		philo->id = i + 1;
		philo->full = false;
		philo->nbr_meals = 0;
		philo->table = table;
		philo->last_meals_time = table->start_simulation;
		philo->have_first = 0;
		philo->have_second = 0;
		philo->thread_id = 0;
		assign_forks(philo, table->forks, i);
		i++;
	}
}

int	data_init(t_table *table)
{
	int	i;

	i = 0;
	table->end_simulation = false;
	table->all_threads_ready = false;
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
	return (0);
}
