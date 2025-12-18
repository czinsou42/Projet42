/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:15:44 by czinsou           #+#    #+#             */
/*   Updated: 2025/05/06 19:24:10 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char )c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char )c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/*int	main()
{
	const char	*str = "Chucky";
	const char	*res1 = strchr(str, 'z');
	const char	*res = ft_strchr(str, 'z');
	printf("Le resultats avec la fonction reecrite est : %s\n", res);
	printf("Le resultats avec la fonction original est : %s\n", res1);
	return (0);
}*/
