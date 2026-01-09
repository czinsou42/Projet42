/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:13:44 by czinsou           #+#    #+#             */
/*   Updated: 2026/01/09 16:51:20 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_end_simulation(t_table *table)
{
	safe_mutex(&table->table_mutex, LOCK);
	table->end_simulation = true;
	safe_mutex(&table->table_mutex, UNLOCK);
}

static int	start_threads(t_table *table, pthread_t *monitor)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		table->philos[i].thread_id = 0;
		if (safe_thread(&table->philos[i].thread_id, philo_routine,
				&table->philos[i], CREATE) == -1)
		{
			set_end_simulation(table);
			return (-1);
		}
		i++;
	}
	if (safe_thread(monitor, routine, table, CREATE) == -1)
	{
		set_end_simulation(table);
		return (-1);
	}
	table->start_simulation = gettime();
	set_bool(&table->table_mutex, &table->all_threads_ready, true);
	return (0);
}

static void	join_threads(t_table *table, pthread_t monitor)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		if (table->philos[i].thread_id)
		{
			safe_thread(&table->philos[i].thread_id, NULL, NULL, JOIN);
			table->philos[i].thread_id = 0;
		}
		i++;
	}
	safe_thread(&monitor, NULL, NULL, JOIN);
}

void	diner_simulation(t_table *table)
{
	pthread_t	monitor;

	if (table->nbr_limit_meals == 0 || table->philo_nbr == 0)
		return ;
	if (start_threads(table, &monitor) == -1)
		return ;
	join_threads(table, monitor);
}

int	main(int argc, char **argv)
{
	t_table	table;
	int		error;

	if (argc != 5 && argc != 6)
	{
		error = error_exit("Format Invalid \n");
		printf(GREEN "Correct format: ./philo 5 800 200 200 [5]" RESET);
		return (error);
	}
	if (parse_arg(&table, argv) == -1)
		return (1);
	if (data_init(&table) == -1)
		return (-1);
	table.start_simulation = gettime();
	philo_init(&table);
	diner_simulation(&table);
	destroy_all(&table);
	return (0);
}
