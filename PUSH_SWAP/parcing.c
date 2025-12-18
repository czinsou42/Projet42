/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:12:41 by czinsou           #+#    #+#             */
/*   Updated: 2025/09/23 15:37:34 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

t_node	*parse_args(int argc, char **argv)
{
	t_node	*stack;
	char	**args;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args)
		{
			return (free_stack(stack), NULL);
		}
		if (!parse_and_add(args, &stack))
			return (free_split(args), free_stack(stack), NULL);
		free_split(args);
		i++;
	}
	return (stack);
}

int	parse_and_add(char **args, t_node **stack)
{
	int		j;
	long	num;
	t_node	*new;

	j = 0;
	while (args[j])
	{
		if (!check_number(args[j]))
			return (print_error());
		num = ft_atol(args[j]);
		if (num < -2147483648 || num > 2147483647)
			return (print_error());
		if (check_duplicate(*stack, num))
			return (print_error());
		new = new_node((int)num);
		if (!new)
			return (print_error());
		ft_addback(stack, new);
		j++;
	}
	return (1);
}
