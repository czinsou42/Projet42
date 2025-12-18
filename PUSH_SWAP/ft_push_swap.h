/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:15:50 by czinsou           #+#    #+#             */
/*   Updated: 2025/09/23 15:28:20 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "Libft1/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

bool				check_number(char *str);
bool				check_duplicate(t_node *head, int nb);
long				ft_atol(const char *str);
t_node				*parse_args(int argc, char **argv);
int					parse_and_add(char **args, t_node **stack);
t_node				*new_node(int value);
void				free_stack(t_node *stack);
void				ft_addback(t_node **head, t_node *new);
void				free_split(char **args);
void				swap(t_node **stack);
void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);
void				push(t_node **src, t_node **dest);
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);
void				rotate(t_node **stack);
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);
void				reverse_rotate(t_node **stack);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);
void				print_stack(t_node *stack);
int					find_max_bits(t_node *stack);
void				assign_index(t_node *stack);
void				radix_sort(t_node **a, t_node **b);
int					is_sorted(t_node *stack);
void				sort_three(t_node **a);
void				sort_two(t_node **a);
void				sort_four(t_node **a, t_node **b);
void				sort_five(t_node **a, t_node **b);
void				move_min_to_top(t_node **a, int pos);
int					find_min_pos(t_node *a);
void				sort_minimal(t_node **a, t_node **b);
int					ft_lstsize(t_node *lst);
#endif