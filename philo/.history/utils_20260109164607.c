/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:44:17 by czinsou           #+#    #+#             */
/*   Updated: 2026/01/09 16:46:07 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	gettime(void)
{
	struct timeval	ts;

	if (gettimeofday(&ts, NULL))
		return (error_exit("Gettimeofday failed"));
	return ((ts.tv_sec * 1000) + (ts.tv_usec / 1000));
}

int	error_exit(const char *msg)
{
	printf(RED "%s\n" RESET, msg);
	return (-1);
}

void	destroy_all(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		if (table->philos[i].thread_id != 0)
		{
			pthread_join(table->philos[i].thread_id, NULL);
			table->philos[i].thread_id = 0;
		}
		i++;
		pthread_mutex_destroy(&table->philos[i].eat_mutex);
	}
	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_mutex_destroy(&table->forks[i].fork);
		i++;
	}
	pthread_mutex_destroy(&table->table_mutex);
	free(table->philos);
	free(table->forks);
}

void	my_usleep(long duration_ms, t_table *table)
{
	long	start_time;

	start_time = gettime();
	while (1)
	{
		safe_mutex(&table->table_mutex, LOCK);
		if (table->end_simulation)
		{
			safe_mutex(&table->table_mutex, UNLOCK);
			return ;
		}
		safe_mutex(&table->table_mutex, UNLOCK);
		if ((gettime() - start_time) >= duration_ms)
			return ;
		usleep(10);
	}
}

bool	get_bool(t_mtx *mtx, bool *b)
{
	bool	ret;

	safe_mutex(mtx, LOCK);
	ret = *b;
	safe_mutex(mtx, UNLOCK);
	return (ret);
}

void	set_bool(t_mtx *mtx, bool *b, bool a)
{
	safe_mutex(mtx, LOCK);
	*b = a;
	safe_mutex(mtx, UNLOCK);
}
