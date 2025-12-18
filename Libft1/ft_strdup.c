/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:50:17 by czinsou           #+#    #+#             */
/*   Updated: 2025/05/06 20:27:04 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*d;

	i = 0;
	d = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(d))
		return (NULL);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

/*int	main()
{
	const char	*src = "Chacha";
	const char	*dest1 = strdup(src);
	const char	*dest2 = ft_strdup(src);
	printf("Le res avec strdup est : %s\n", dest1);
	printf("Le res avec ft_strdup est : %s\n", dest2);
	return (0);
}*/
