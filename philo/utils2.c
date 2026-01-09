/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:59:49 by czinsou           #+#    #+#             */
/*   Updated: 2026/01/09 16:00:22 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
