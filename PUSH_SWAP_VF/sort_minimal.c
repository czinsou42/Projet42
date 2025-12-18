/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_minimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:53:39 by czinsou           #+#    #+#             */
/*   Updated: 2025/09/23 13:46:51 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_three(t_node **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

void	sort_two(t_node **a)
{
	int	x;
	int	y;

	x = (*a)->value;
	y = (*a)->next->value;
	if (x > y)
	{
		sa(a);
	}
}

void	sort_four(t_node **a, t_node **b)
{
	int	pos;

	pos = find_min_pos(*a);
	if (pos == 1)
		ra(a);
	else if (pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (pos == 3)
		rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_node **a, t_node **b)
{
	int	pos;

	pos = find_min_pos(*a);
	move_min_to_top(a, pos);
	pb(a, b);
	pos = find_min_pos(*a);
	move_min_to_top(a, pos);
	pb(a, b);
	sort_three(a);
	if ((*b)->value < (*b)->next->value)
		sb(b);
	pa(a, b);
	pa(a, b);
}

void	sort_minimal(t_node **a, t_node **b)
{
	if (ft_lstsize(*a) == 3)
	{
		sort_three(a);
	}
	else if (ft_lstsize(*a) == 2)
	{
		sort_two(a);
	}
	else if (ft_lstsize(*a) == 4)
	{
		sort_four(a, b);
	}
	else if (ft_lstsize(*a) == 5)
	{
		sort_five(a, b);
	}
}
