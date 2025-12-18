/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:09:39 by czinsou           #+#    #+#             */
/*   Updated: 2025/05/06 19:25:06 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	last = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char )c)
			last = ((char *)&s[i]);
		i++;
	}
	if ((char )c == '\0')
		return ((char *)&s[i]);
	return (last);
}

/*int	main()
{
	const char      *str = "Chucky";
        const char      *res = strrchr(str, 'z');
        const char      *res1 = ft_strrchr(str, 'z');
        printf("Le resultats avec la fonction original est : %s\n", res);
        printf("Le resultats avec la fonction reecrite est : %s\n", res1);
        return (0);
}*/
