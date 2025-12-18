/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:19:18 by czinsou           #+#    #+#             */
/*   Updated: 2025/05/12 13:42:53 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *) malloc(sizeof (char) * (len1 + len2 + 1));
	if (!(res))
		return (NULL);
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

/*int	main()
{
	char	*res;
	res =ft_strjoin("Char","bel");
	printf("%s", res);
	return (0);
}*/