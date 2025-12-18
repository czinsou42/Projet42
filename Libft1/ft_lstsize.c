/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:58:12 by czinsou           #+#    #+#             */
/*   Updated: 2025/05/19 11:40:45 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

// int	main(void)
// {
// 	t_list	*elt1 = ft_lstnew("Premier");
// 	t_list	*elt2 = ft_lstnew("Deuxieme");
// 	t_list	*elt3 = ft_lstnew("Troisieme");

// 	ft_lstadd_front(&elt1, elt2);
// 	ft_lstadd_front(&elt1, elt3);

// 	printf("%d\n", ft_lstsize(elt3));
// 	return (0);
// }