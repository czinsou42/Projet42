/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:04:12 by czinsou           #+#    #+#             */
/*   Updated: 2025/07/10 17:13:42 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_push_swap.h"

bool	check_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str)
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	is_duplicate(t_node *head, int nb)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp == nb)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

t_node	*new_node(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	free_allnode(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

