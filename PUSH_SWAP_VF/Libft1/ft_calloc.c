/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:25:58 by czinsou           #+#    #+#             */
/*   Updated: 2025/05/12 19:46:15 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*str;
	size_t			i;
	unsigned char	*p;

	i = 0;
	if ((nmemb == 0) || (size == 0))
		return (malloc(0));
	str = malloc(nmemb * size);
	if (!(str))
		return (NULL);
	p = (unsigned char *)str;
	while (i < (nmemb * size))
	{
		p[i] = 0;
		i++;
	}
	return (str);
}
