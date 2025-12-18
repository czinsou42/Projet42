/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:19:42 by czinsou           #+#    #+#             */
/*   Updated: 2025/09/23 15:20:00 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	find_max_bits(t_node *stack)
{
	int	max_value;
	int	bits;
	int	i;

	if (stack == NULL)
		return (0);
	max_value = stack->index;
	while (stack != NULL)
	{
		if (stack->index > max_value)
			max_value = stack->index;
		stack = stack->next;
	}
	bits = 0;
	i = max_value;
	while (i > 0)
	{
		bits++;
		i = i / 2;
	}
	return (bits);
}

void	assign_index(t_node *stack)
{
	t_node	*current;
	t_node	*other;
	int		index;

	current = stack;
	while (current != NULL)
	{
		index = 0;
		other = stack;
		while (other != NULL)
		{
			if ((other->value) < (current->value))
				index++;
			other = other->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	radix_sort(t_node **a, t_node **b)
{
	int	size;
	int	max_bits;
	int	bits;
	int	i;

	size = ft_lstsize(*a);
	max_bits = find_max_bits(*a);
	bits = 0;
	while (bits < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((((*a)->index) >> bits) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (*b != NULL)
			pa(a, b);
		bits++;
	}
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if ((stack->value) > (stack->next->value))
			return (0);
		stack = stack->next;
	}
	return (1);
}
