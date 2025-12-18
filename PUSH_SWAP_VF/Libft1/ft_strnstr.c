/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:05:05 by czinsou           #+#    #+#             */
/*   Updated: 2025/05/15 18:09:03 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (s2[0] == '\0')
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j) < n && s2[j])
			j++;
		if (s2[j] == '\0')
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char      *str = "Charbel est beau";
	const char	*to_find = "est";
		const char      *res1 = strnstr(str, to_find,12);
		const char      *res = ft_strnstr(str, to_find, 12);
		printf("Berny : %s\n", res);
		printf("Berny : %s\n", res1);
		return (0);
}*/
