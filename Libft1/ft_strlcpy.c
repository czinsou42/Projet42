/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:18:50 by czinsou           #+#    #+#             */
/*   Updated: 2025/05/15 17:48:28 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (s2[i] && i < (n - 1))
		{
			s1[i] = s2[i];
			i++;
		}
		s1[i] = '\0';
	}
	while (s2[i])
		i++;
	return (i);
}
/*int	main()
{
	char	s1[] = "Chacha";
	char	s2[] = "";
	//printf("%zu\n",strlcpy(s1, s2, 3));
	printf("%zu", ft_strlcpy(s1,s2, 3));
	return (0);
}*/
