/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:18:35 by czinsou           #+#    #+#             */
/*   Updated: 2025/09/17 17:51:45 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack ||!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
	{
		last = last->next;
	}
	last->next = first;
	first->next = NULL;
}

void	ra(t_node **a)
{
	rotate(a);
	write (1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate(b);
	write (1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write (1, "rr\n", 3);
}
