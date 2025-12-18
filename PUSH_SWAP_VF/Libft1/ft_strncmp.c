/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:49:10 by czinsou           #+#    #+#             */
/*   Updated: 2025/09/23 15:37:05 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*int	main()
{
	const char *s1 = "Chacha";
	const char *s2 = "Chucky";
	printf("La rps avec la bonne fonction est : %d\n", strncmp(s1, s2, 1));
	printf("La rps avec la fonction reecrite est : %d\n", ft_strncmp(s1, s2, 1));
	return (0);
}*/
