/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:18:26 by czinsou           #+#    #+#             */
/*   Updated: 2026/01/09 15:58:25 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_forks(t_philo *philo, t_mutex_action action)
{
	if (action == LOCK)
	{
		if (safe_mutex(&philo->first_fork->fork, LOCK) == -1)
			return ;
		philo->have_first = 1;
		print_action(philo, "has taken a fork");
		if (safe_mutex(&philo->second_fork->fork, LOCK) == -1)
			return ((void)(safe_mutex(&philo->first_fork->fork, UNLOCK),
				philo->have_first = 0));
		philo->have_second = 1;
		print_action(philo, "has taken a fork");
	}
	else
	{
		if (philo->have_second)
		{
			safe_mutex(&philo->second_fork->fork, UNLOCK);
			philo->have_second = 0;
		}
		if (philo->have_first)
		{
			safe_mutex(&philo->first_fork->fork, UNLOCK);
			philo->have_first = 0;
		}
	}
}

void	philo_eat(t_philo *philo)
{
	if (safe_mutex(&philo->table->table_mutex, LOCK) == -1)
		return ;
	philo->last_meals_time = gettime();
	philo->nbr_meals += 1;
	if (safe_mutex(&philo->table->table_mutex, UNLOCK) == -1)
		return ;
	print_action(philo, "is eating");
	my_usleep(philo->table->time_to_eat, philo->table);
}

void	philo_think(t_philo *philo)
{
	long	think;

	if (philo->table->philo_nbr % 2 == 0)
		return ;
	think = philo->table->time_to_eat * 2 - philo->table->time_to_sleep;
	if (think < 0)
		think = 0;
	print_action(philo, "is thinking");
	my_usleep(think * 0.42, philo->table);
}

void	mini_routine(t_philo *philo)
{
	handle_forks(philo, LOCK);
	philo_eat(philo);
	handle_forks(philo, UNLOCK);
	print_action(philo, "is sleeping");
	my_usleep(philo->table->time_to_sleep, philo->table);
	philo_think(philo);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!get_bool(&philo->table->table_mutex, &philo->table->end_simulation))
	{
		if (get_bool(&philo->table->table_mutex,
				&philo->table->all_threads_ready) == true)
			break ;
		my_usleep(1, philo->table);
	}
	if (philo->id % 2 == 0)
		my_usleep(philo->table->time_to_eat / 2, philo->table);
	while (1)
	{
		pthread_mutex_lock(&philo->table->table_mutex);
		if (philo->table->end_simulation)
		{
			pthread_mutex_unlock(&philo->table->table_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->table->table_mutex);
		mini_routine(philo);
	}
	return (NULL);
}
