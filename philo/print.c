/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:02:25 by czinsou           #+#    #+#             */
/*   Updated: 2025/12/04 17:27:19 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_death(t_philo *philo, const char *action)
{
	long	timestamp;

	timestamp = gettime() - philo->table->start_simulation;
	printf("%ld %d %s\n", timestamp, philo->id, action);
}

void	print_action(t_philo *philo, const char *action)
{
	long	timestamp;

	if (safe_mutex(&philo->table->table_mutex, LOCK) == -1)
		return ;
	if (!philo->table->end_simulation)
	{
		timestamp = gettime() - philo->table->start_simulation;
		printf("%ld %d %s\n", timestamp, philo->id, action);
	}
	if (safe_mutex(&philo->table->table_mutex, UNLOCK) == -1)
		return ;
}
