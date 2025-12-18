/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:50:56 by czinsou           #+#    #+#             */
/*   Updated: 2025/05/06 19:21:15 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = '\0';
}

/*int	main()
{
	char str[6]= "Chacha";
        printf("%s\n", str);
        bzero(str, 3);
	printf("%s\n\n", str);
        ft_bzero(str,6);
	printf("%s\n", str);
        return (0);
}*/
