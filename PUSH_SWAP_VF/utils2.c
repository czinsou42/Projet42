/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:56:32 by czinsou           #+#    #+#             */
/*   Updated: 2025/09/23 15:37:45 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	find_min_pos(t_node *a)
{
	int		min;
	int		pos;
	int		i;
	t_node	*tmp;

	i = 0;
	pos = 0;
	min = a->value;
	tmp = a;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	move_min_to_top(t_node **a, int pos)
{
	int	len;

	len = ft_lstsize(*a);
	if (pos <= len / 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < len)
			rra(a);
}
