/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:11:44 by czinsou           #+#    #+#             */
/*   Updated: 2025/05/06 20:28:44 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	i;

	d = ft_strlen(dest);
	s = ft_strlen(src);
	i = 0;
	if (size <= d)
		return (s + size);
	while (src[i] && (d + i) < (size - 1))
	{
		dest[d + i] = src[i];
		i++;
	}
	dest[d + i] = '\0';
	return (d + s);
}

/*int	main()
{
	char    s1[] = "Chacha";
        char    s2[] = "";
        printf("%zu\n",strlcat(s1, s2, 3));
        //printf("%zu", ft_strlcat(s1,s2, 3));
        return (0);
}*/
