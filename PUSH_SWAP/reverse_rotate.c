/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:20:06 by czinsou           #+#    #+#             */
/*   Updated: 2025/09/17 17:52:32 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	reverse_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack ||!(*stack) || !(*stack)->next)
		return ;
	first = NULL;
	last = *stack;
	while (last->next)
	{
		first = last;
		last = last->next;
	}
	first->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_node **a)
{
	reverse_rotate(a);
	write (1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	write (1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write (1, "rrr\n", 4);
}
