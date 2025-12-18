/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:26:53 by czinsou           #+#    #+#             */
/*   Updated: 2025/10/02 14:19:07 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	count_words(const char *s)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (!is_space(*s) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_space(*s))
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*malloc_word(const char *s)
{
	int		len;
	char	*word;

	len = 0;
	while (s[len] && !is_space(s[len]))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	len = 0;
	while (s[len] && !is_space(s[len]))
	{
		word[len] = s[len];
		len++;
	}
	word[len] = '\0';
	return (word);
}

static void	free_all(char **tab, int j)
{
	while (j-- > 0)
		free(tab[j]);
	free(tab);
}

char	**ft_split(char const *s)
{
	char	**tab;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(s) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		if (!is_space(*s))
		{
			tab[i] = malloc_word(s);
			if (!tab[i])
				return (free_all(tab, i), NULL);
			i++;
			while (*s && !is_space(*s))
				s++;
		}
		else
			s++;
	}
	tab[i] = NULL;
	return (tab);
}

int	main(void)
{
	size_t	i = 0;
	size_t	j = 0;
	char	**res = 0;
	res = ft_split("Charbel est beau et Amine est muscle");
	while (res[i])
	{
		j = 0;
		while (res[i][j])
		{
			printf("%c",res[i][j]);
			j++;
		}
		printf("\n");
		free (res[i]);
		i++;
	}
	free (res);
	return (0);
}