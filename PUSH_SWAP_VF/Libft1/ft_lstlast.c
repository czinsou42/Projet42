/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:17:03 by czinsou           #+#    #+#             */
/*   Updated: 2025/05/19 12:30:49 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
// int	main(void)
// {
// 	t_list	*elt1 = ft_lstnew("Premier");
// 	t_list	*elt2 = ft_lstnew("Deuxieme");
// 	t_list	*elt3 = ft_lstnew("Troisieme");

// 	ft_lstadd_back(&elt1, elt2);
// 	ft_lstadd_back(&elt1, elt3);
// 	t_list	*last = ft_lstlast(elt1);
// 	printf("%d\n", (char *)last->content);
// 	return (0);
// }