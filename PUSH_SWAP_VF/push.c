/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:20:06 by czinsou           #+#    #+#             */
/*   Updated: 2025/08/14 12:46:50 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*tmp;

	if (!src || !(*src))
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pa(t_node **a, t_node **b)
{
	push(b, a);
	write (1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	push(a, b);
	write (1, "pb\n", 3);
}
