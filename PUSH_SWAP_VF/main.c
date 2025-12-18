/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:29:17 by czinsou           #+#    #+#             */
/*   Updated: 2025/09/23 15:25:19 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	print_stack(t_node *stack)
{
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
}

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	b = NULL;
	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	if (!a)
		return (1);
	if (is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	if (ft_lstsize(a) <= 5)
		sort_minimal(&a, &b);
	else
	{
		assign_index(a);
		radix_sort(&a, &b);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
