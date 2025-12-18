/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:33:15 by czinsou           #+#    #+#             */
/*   Updated: 2025/05/12 15:17:05 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*res;

	end = ft_strlen(s1);
	start = 0;
	while (s1[start] && (ft_strchr(set, s1[start])))
		start++;
	while ((end > start) && (ft_strchr(set, s1[end - 1])))
		end--;
	res = (char *) malloc(sizeof (char ) * (end - start + 1));
	if (!(res))
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		res[i] = s1[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// int	main()
// {
// 	char	*res;
// 	res = ft_strtrim("abcCharbelabc", "set");
// 	printf("%s\n", res);
// 	return (0);
// }