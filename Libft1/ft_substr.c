/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:50:00 by czinsou           #+#    #+#             */
/*   Updated: 2025/05/12 13:16:50 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > (slen - start))
		len = slen - start;
	substr = (char *) malloc(sizeof(char) * (len + 1));
	if (!(substr))
		return (NULL);
	while (s[start + i] && (i < len))
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

/*int	main()
{
	char	*res;
	res = ft_substr("Hello World", 6, 5);
	printf("%s\n", res);
	return (0);
}*/